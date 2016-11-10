#include "stdafx.h"
#include "Packet.h"
#include "PCAPHeader.h"
#include "PCAPRecord.h"

Yellow::PCAP::Record::Record(std::shared_ptr<Yellow::Packet> packet)
  : _packet(packet)
{
  std::chrono::high_resolution_clock::duration  tp = _packet->getTimePoint().time_since_epoch();

  _hdr.ts_sec = std::chrono::duration_cast<std::chrono::seconds>(tp).count();
  tp -= std::chrono::duration_cast<std::chrono::seconds>(tp);
  _hdr.ts_usec = std::chrono::duration_cast<std::chrono::microseconds>(tp).count();
  _hdr.orig_len  = _packet->getLenght();
  _hdr.incl_len = 0;
}

Yellow::PCAP::Record::Record()
  : _packet(nullptr)
{
}

Yellow::PCAP::Record::~Record()
{
}

const Yellow::PCAP::RecordHeader      &Yellow::PCAP::Record::getHeader() const
{
  return _hdr;
}

const std::shared_ptr<Yellow::Packet> Yellow::PCAP::Record::getPacket() const
{
  return _packet;
}

std::ostream &Yellow::PCAP::operator<<(std::ostream &output, Yellow::PCAP::Record &user)
{
  if (user._packet == nullptr)
    return output;
  user._hdr.incl_len = user._hdr.orig_len;
  output.write(reinterpret_cast<char *>(&user._hdr), sizeof(user._hdr));
  if (!output || output.eof())
    return (output);
  output.write(reinterpret_cast<const char *>((*user._packet)[0]), user._packet->getLenght());
  return output;
}


std::istream &Yellow::PCAP::operator>>(std::istream &input, Yellow::PCAP::Record &user)
{
  void                  *buff;

  input.read(reinterpret_cast<char *>(&user._hdr), sizeof(user._hdr));
  if (!input || input.eof())
    return (input);
  buff = new unsigned char[user._hdr.incl_len];
  input.read(reinterpret_cast<char *>(buff), user._hdr.incl_len);
  if (!input || input.eof())
    return input;
  user._packet = std::make_shared<Yellow::Packet>(buff, static_cast<unsigned int>(user._hdr.incl_len));
  return input;
}
