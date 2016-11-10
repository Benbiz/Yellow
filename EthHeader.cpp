#include "stdafx.h"
#include "EthHeader.h"

Yellow::EthHeader::EthHeader(void * begin)
  : buff(static_cast<unsigned char *>(begin)), eth(static_cast<struct ethhdr *>(begin))
{

}

Yellow::EthHeader::EthHeader(const EthHeader &e)
{
  buff = e.buff;
  eth = e.eth;
}

Yellow::EthHeader & Yellow::EthHeader::operator=(const EthHeader &e)
{
  buff = e.buff;
  eth = e.eth;
  return (*this);
}

Yellow::EthHeader::~EthHeader()
{
}

void Yellow::EthHeader::setSource(const MACAddress addr)
{
  memcpy(eth->h_source, addr, 6);
}

const Yellow::EthHeader::MACAddress Yellow::EthHeader::getSource() const
{
  return eth->h_source;
}

void Yellow::EthHeader::setDest(const MACAddress addr)
{
  memcpy(eth->h_dest, addr, 6);
}

const Yellow::EthHeader::MACAddress Yellow::EthHeader::getDest() const
{
  return eth->h_dest;
}

const unsigned short int Yellow::EthHeader::getProto() const
{
  return eth->h_proto;
}

const unsigned char *Yellow::EthHeader::operator[](const int idx) const
{
  if (idx >= getLenght())
    return NULL;
  return &static_cast<const unsigned char *>(buff)[idx];
}

const int Yellow::EthHeader::getLenght() const
{
  return sizeof(struct ethhdr);
}
