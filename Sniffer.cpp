#include "stdafx.h"
#include "Sniffer.h"

Yellow::Sniffer::Sniffer()
  : _sock(-1), _state(Yellow::Sniffer::Status::Init)
{
}

Yellow::Sniffer::~Sniffer()
{
  _state = Yellow::Sniffer::Status::Destroyed;
  if (_sock != -1)
    close(_sock);
}

std::shared_ptr<Yellow::Packet> Yellow::Sniffer::getPacket()
{
  int				dataSize = 0;
  unsigned char			*buff;
  struct sockaddr		saddr;
  unsigned int			saddr_size;
  std::shared_ptr<Packet>	packet;

  if(_state != Yellow::Sniffer::Status::Started)
    return nullptr;
  buff = new unsigned char[65536];
  while (packet == nullptr)
    {
      saddr_size = sizeof(saddr);
      dataSize = recvfrom(_sock, buff, 65536, 0, &saddr, static_cast<socklen_t *>(&saddr_size));
      if (dataSize < 0)
        {
          _state = Yellow::Sniffer::Status::Failed;
          delete[] buff;
          return nullptr;
        }
      else if (dataSize == 0 && _state != Yellow::Sniffer::Status::Started)
        {
          delete [] buff;
          return nullptr;
        }
      else if (_state != Yellow::Sniffer::Status::Started)
        {
          delete[] buff;
          return nullptr;
        }
      try
        {
          packet = std::make_shared<Packet>(buff, dataSize);
        }
      catch (const std::exception &e)
        {
          std::cout << "Error while creating packet: " << e.what() << std::endl;
          packet = nullptr;
        }
    }

  return (packet);
}

bool Yellow::Sniffer::start()
{
  int         m_if_index;

  _state = Yellow::Sniffer::Status::Started;
  _sock = socket(PF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
  if (_sock < 0)
    {
      _state = Yellow::Sniffer::Status::Failed;
      return false;
    }
  struct ifreq ifr = {0};

  strncpy(ifr.ifr_name, "eth0", IFNAMSIZ);

  if (ioctl(_sock, SIOCGIFINDEX, &ifr) != 0)
    return false;
  m_if_index = ifr.ifr_ifindex;
  struct packet_mreq mreq = {0};

  mreq.mr_ifindex = m_if_index;
  mreq.mr_type = PACKET_MR_PROMISC;

  if (setsockopt(_sock, SOL_PACKET, PACKET_ADD_MEMBERSHIP, &mreq, sizeof(mreq)) != 0)
    return false;
  return true;
}

void Yellow::Sniffer::stop()
{
  _state = Yellow::Sniffer::Status::Closed;
  if (_sock != -1)
    {
      shutdown(_sock, SHUT_RDWR);
      close(_sock);
      _sock = -1;
    }
}
