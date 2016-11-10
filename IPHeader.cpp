#include "stdafx.h"
#include "IPHeader.h"

Yellow::IPHeader::IPHeader(void * begin)
  : buff(static_cast<unsigned char *>(begin)), ip(static_cast<struct iphdr *>(begin))
{
  memset(&sourceaddr, 0, sizeof(sourceaddr));
  sourceaddr.sin_addr.s_addr = ip->saddr;
  source = inet_ntoa(sourceaddr.sin_addr);

  memset(&destaddr, 0, sizeof(destaddr));
  destaddr.sin_addr.s_addr = ip->daddr;
  dest = inet_ntoa(destaddr.sin_addr);
}

Yellow::IPHeader::IPHeader(const IPHeader &i)
{
  buff = i.buff;
  ip = i.ip;
}

Yellow::IPHeader & Yellow::IPHeader::operator=(const IPHeader &i)
{
  buff = i.buff;
  ip = i.ip;
  return *this;
}

Yellow::IPHeader::~IPHeader()
{
}

void Yellow::IPHeader::setVersion(unsigned int ver)
{
  ip->version = ver;
}

const unsigned int Yellow::IPHeader::getVesion() const
{
  return ip->version;
}

void Yellow::IPHeader::setHeaderLenght(unsigned int nbWord)
{
  ip->ihl = nbWord / 4;
}

const unsigned int Yellow::IPHeader::getHeaderLenght() const
{
  return (ip->ihl * 4);
}

void Yellow::IPHeader::setTypeOfService(unsigned int tos)
{
  ip->tos = tos;
}

const unsigned int Yellow::IPHeader::getTypeOfService() const
{
  return (ip->tos);
}

void Yellow::IPHeader::setTotalLenght(unsigned short int tot)
{
  ip->tot_len = htons(tot);
}

const unsigned short int Yellow::IPHeader::getTotalLenght() const
{
  return ntohs(ip->tot_len);
}

void Yellow::IPHeader::setIdentification(unsigned short int id)
{
  ip->id = htons(id);
}

const unsigned short Yellow::IPHeader::getIndentification() const
{
  return ntohs(ip->id);
}

void Yellow::IPHeader::setTTL(unsigned int ttl)
{
  ip->ttl = ttl;
}

const unsigned int Yellow::IPHeader::getTTL() const
{
  return ip->ttl;
}

void Yellow::IPHeader::setProtocol(unsigned int proto)
{
  ip->protocol = proto;
}

const unsigned int Yellow::IPHeader::getProtocol() const
{
  return ip->protocol;
}

void Yellow::IPHeader::setChecksum(unsigned short int check)
{
  ip->check = htons(check);
}

const unsigned short int Yellow::IPHeader::getChecksum() const
{
  return ntohs(ip->check);
}

void Yellow::IPHeader::setSourceIP(const std::string &addr)
{
  inet_aton(addr.c_str(), &sourceaddr.sin_addr);
  ip->saddr = sourceaddr.sin_addr.s_addr;
  source = addr;
}

const std::string   &Yellow::IPHeader::getSourceIP() const
{
  return source;
}

void Yellow::IPHeader::setDestIP(const std::string &addr)
{
  inet_aton(addr.c_str(), &destaddr.sin_addr);
  ip->daddr = destaddr.sin_addr.s_addr;
  dest = addr;
}

const std::string   &Yellow::IPHeader::getDestinationIP() const
{
  return dest;
}

const unsigned char * Yellow::IPHeader::operator[](int idx) const
{
  if (idx >= getHeaderLenght())
    return NULL;
  return &static_cast<const unsigned char *>(buff)[idx];
}
