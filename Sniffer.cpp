#include "stdafx.h"
#include "Sniffer.h"

Yellow::Sniffer::Sniffer()
  : _sock(-1)
{
}

Yellow::Sniffer::~Sniffer()
{
  if (_sock != -1)
    close(_sock);
}

std::shared_ptr<Yellow::Packet> Yellow::Sniffer::getPacket()
{
  int               dataSize = 0;
  unsigned char     *buff = new unsigned char[65536];
  struct sockaddr   saddr;
  unsigned int      saddr_size;


  saddr_size = sizeof(saddr);
  dataSize = recvfrom(_sock, buff, 65536, 0, &saddr, static_cast<socklen_t *>(&saddr_size));
  if (dataSize < 0)
    return nullptr;
  return (std::make_shared<Packet>(buff, dataSize));
}

bool Yellow::Sniffer::start()
{
  _sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  if (_sock < 0)
    return false;
  return true;
}
