#include "stdafx.h"
#include "Sniffer.h"

int		main()
{
  Yellow::Sniffer s;
  std::shared_ptr<Yellow::Packet> pack;

  if (!s.start())
    {
      std::cout << "Fail tu start" << std::endl;
      return 0;
    }
  while ((pack = s.getPacket()) != nullptr)
    {
      std::cout << "Source IP : " << pack->getIPHeader().getSourceIP()
                << ", Destination IP :" << pack->getIPHeader().getDestinationIP() << std::endl;
    }
  return 0;
}
