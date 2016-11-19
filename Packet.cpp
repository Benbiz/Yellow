#include "stdafx.h"
#include "TCPHeader.h"
#include "UDPHeader.h"
#include "Packet.h"

Yellow::Packet::Packet(void *buffer, int lenght)
  : buff(static_cast<unsigned char *>(buffer)), eth(buff), ip(buff + eth.getLenght()), len(lenght),
    tp(std::chrono::high_resolution_clock::now())
{
  if (eth.getProto() != 8)
    throw std::invalid_argument("Not IP packet");
  switch (ip.getProtocol())
    {
    case IPPROTO_TCP: //TCP
      tl = std::make_shared<Yellow::TCPHeader>(buff + eth.getLenght() + ip.getHeaderLenght());
      break;
    case IPPROTO_UDP: // UDP
      tl = std::make_shared<Yellow::UDPHeader>(buff + eth.getLenght() + ip.getHeaderLenght());
      break;
    default:
      throw std::invalid_argument("Transport Protocol not supported");
      break;
    }
}

Yellow::Packet::~Packet()
{
  delete[] buff;
}

const Yellow::EthHeader						&Yellow::Packet::getEthHeader() const
{
  return eth;
}

const Yellow::IPHeader						&Yellow::Packet::getIPHeader() const
{
  return ip;
}

const std::shared_ptr<Yellow::ITLHeader>	Yellow::Packet::getTLHeader() const
{
  return (tl);
}

const unsigned char							*Yellow::Packet::operator[](int idx) const
{
  if (idx >= len)
    return NULL;
  return (&buff[idx]);
}

const int                       Yellow::Packet::getLenght() const
{
  return len;
}

std::chrono::high_resolution_clock::time_point  &Yellow::Packet::getTimePoint()
{
  return (tp);
}
