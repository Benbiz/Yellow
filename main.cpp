#include "stdafx.h"
#include "PCAPRecorder.h"
#include "Sniffer.h"

int		main()
{
  Yellow::Sniffer s;
  Yellow::PCAP::Recorder  rec;

  std::shared_ptr<Yellow::Packet> pack;
  std::ofstream ofs ("test.txt", std::ofstream::out | std::ofstream::trunc | std::ofstream::binary);
  if (!ofs)
    {
      std::cout << "fail to get file" << std::endl;
      return 0;
    }

  if (!s.start())
    {
      std::cout << "Fail tu start" << std::endl;
      return 0;
    }
  while ((pack = s.getPacket()) != nullptr)
    {
      rec.addRecord(pack);
      ofs << rec;
      ofs.seekp(std::ios_base::beg);
      std::cout << "Source IP : " << pack->getIPHeader().getSourceIP()
		<< ", Destination IP :" << pack->getIPHeader().getDestinationIP() << std::endl;
    }
  return 0;
}
