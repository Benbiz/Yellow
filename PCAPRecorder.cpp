#include "stdafx.h"
#include "Packet.h"
#include "PCAPHeader.h"
#include "PCAPRecord.h"
#include "PCAPRecorder.h"


Yellow::PCAP::Recorder::Recorder()
{
  _gheader.magic_number = 0xa1b2c3d4;
  _gheader.version_major = 2;
  _gheader.version_minor = 4;
  _gheader.thiszone = 0;
  _gheader.sigfigs = 0;
  _gheader.snaplen = 655335;
  _gheader.network = 1;
}

Yellow::PCAP::Recorder::~Recorder()
{
}

const Yellow::PCAP::GlobalHeader                          &Yellow::PCAP::Recorder::getGlobalHeader() const
{
  return _gheader;
}

const std::vector<std::shared_ptr<Yellow::PCAP::Record>>  &Yellow::PCAP::Recorder::getRecords() const
{
  return _records;
}

std::shared_ptr<Yellow::PCAP::Record>                                    Yellow::PCAP::Recorder::addRecord(std::shared_ptr<Yellow::PCAP::Record> rec)
{
  _records.push_back(rec);
  return rec;
}

std::shared_ptr<Yellow::PCAP::Record>		            Yellow::PCAP::Recorder::addRecord(std::shared_ptr<Yellow::Packet> pack)
{
  std::shared_ptr<Record>	rec = std::make_shared<Yellow::PCAP::Record>(pack);
  _records.push_back(rec);

  return rec;
}

std::ostream            &Yellow::PCAP::operator<<(std::ostream &output, Yellow::PCAP::Recorder &rec)
{
  output.write(reinterpret_cast<char *>(&rec._gheader), sizeof(rec._gheader));
  if (!output || output.eof())
    return (output);
  for (std::shared_ptr<Yellow::PCAP::Record> record : rec._records)
    output << *record;
  return output;
}

std::istream            &Yellow::PCAP::operator>>(std::istream &input, Yellow::PCAP::Recorder &rec)
{
  std::shared_ptr<Yellow::PCAP::Record> record;

  input.read(reinterpret_cast<char *>(&rec._gheader), sizeof(rec._gheader));
  if (!input || input.eof())
    return (input);

  rec._records.clear();
  record = std::make_shared<Yellow::PCAP::Record>();
  while (input >> *record)
    {
      rec._records.push_back(record);
      record = std::make_shared<Yellow::PCAP::Record>();
    }
  return input;
}
