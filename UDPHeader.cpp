#include "stdafx.h"
#include "UDPHeader.h"

Yellow::UDPHeader::UDPHeader(void *beg)
  : udp(static_cast<struct udphdr *>(beg)), buff(static_cast<unsigned char *>(beg))
{
}

Yellow::UDPHeader::UDPHeader(const UDPHeader &u)
{
  udp = u.udp;
  buff = u.buff;
}

Yellow::UDPHeader &Yellow::UDPHeader::operator=(const UDPHeader &u)
{
  udp = u.udp;
  buff = u.buff;
  return *this;
}

Yellow::UDPHeader::~UDPHeader()
{
}

const unsigned char			*Yellow::UDPHeader::operator[](int idx) const
{
  if (idx >= getLenght())
    return NULL;
  return (&buff[idx]);
}

const int				Yellow::UDPHeader::getLenght() const
{
  return (sizeof (struct udphdr));
}

const unsigned short int			Yellow::UDPHeader::getSourcePort() const
{
  return (udp->source);
}

void					Yellow::UDPHeader::setSourcePort(const unsigned short int source)
{
  udp->source = source;
}

const unsigned short int			Yellow::UDPHeader::getDestPort() const
{
  return (udp->dest);
}

void					Yellow::UDPHeader::setDestPort(const unsigned short int dest)
{
  udp->dest = dest;
}

const unsigned short int			Yellow::UDPHeader::getUDPLenght() const
{
  return udp->len;
}

void					Yellow::UDPHeader::setUDPLenght(const unsigned short int len)
{
  udp->len = len;
}

const unsigned short int			Yellow::UDPHeader::getChecksum() const
{
  return (udp->check);
}

void					Yellow::UDPHeader::setChecksum(const unsigned short int check)
{
  udp->check = check;
}
