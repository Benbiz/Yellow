#include "stdafx.h"
#include "TCPHeader.h"

Yellow::TCPHeader::TCPHeader(void *begin)
  :buff(static_cast<unsigned char *>(begin)), tcp(static_cast<struct tcphdr *>(begin))
{

}

Yellow::TCPHeader::~TCPHeader()
{
}

const unsigned char		*Yellow::TCPHeader::operator[](int idx) const
{
  if (idx >= getHeaderLenght())
    return NULL;
   return &buff[idx];
}

const int             Yellow::TCPHeader::getLenght() const
{
  return (getHeaderLenght());
}

void					Yellow::TCPHeader::setSourcePort(const unsigned short int port)
{
  tcp->source = htons(port);
}

const unsigned short int		Yellow::TCPHeader::getSourcePort() const
{
  return ntohs(tcp->source);
}

void					Yellow::TCPHeader::setDestPort(const unsigned short int port)
{
  tcp->dest = htons(port);
}

const unsigned short int		Yellow::TCPHeader::getDestPort() const
{
  return ntohs(tcp->dest);
}

void					Yellow::TCPHeader::setSequenceNumber(const unsigned short int nb)
{
  tcp->seq = nb;
}

const unsigned short int		Yellow::TCPHeader::getSequenceNumber() const
{
  return tcp->seq;
}

void					Yellow::TCPHeader::setAcknowledgeNumber(const unsigned short int nb)
{
  tcp->ack_seq = nb;
}

const unsigned short int		Yellow::TCPHeader::getAcknowledgeNumber() const
{
  return tcp->ack_seq;
}

void					Yellow::TCPHeader::setHeaderLenght(const unsigned int lenghtWord)
{
  tcp->doff = lenghtWord / 4;
}

const unsigned int			Yellow::TCPHeader::getHeaderLenght() const
{
  return tcp->doff * 4;
}

void					Yellow::TCPHeader::setUrgentFlag(const unsigned int urg)
{
  tcp->urg = urg;
}

const unsigned int			Yellow::TCPHeader::getUrgentFlag() const
{
  return tcp->urg;
}

void					Yellow::TCPHeader::setAcknowledgementFlag(const unsigned int ack)
{
  tcp->ack = ack;
}

const unsigned int			Yellow::TCPHeader::getAcknowledgementFlag() const
{
  return tcp->ack;
}

void					Yellow::TCPHeader::setPushFlag(const unsigned int push)
{
  tcp->psh = push;
}

const unsigned int			Yellow::TCPHeader::getPushFlag() const
{
  return tcp->psh;
}

void                    Yellow::TCPHeader::setResetFlag(const unsigned int rst)
{
  tcp->rst = rst;
}

const unsigned int            Yellow::TCPHeader::getResetFlag() const
{
  return tcp->rst;
}

void                    Yellow::TCPHeader::setSynchroniseFlag(const unsigned int sync)
{
  tcp->syn = sync;
}

const unsigned int			Yellow::TCPHeader::getSynchroniseFlag() const
{
  return tcp->syn;
}

void					Yellow::TCPHeader::setFinishFlag(const unsigned int fin)
{
  tcp->fin = fin;
}

const unsigned int			Yellow::TCPHeader::getFinishFlag() const
{
  return tcp->fin;
}

void					Yellow::TCPHeader::setWindow(const unsigned short int win)
{
  tcp->window = htons(win);
}

const unsigned short int		Yellow::TCPHeader::getWindow() const
{
  return ntohs(tcp->window);
}

void					Yellow::TCPHeader::seChecksum(const unsigned short int check)
{
  tcp->check = htons(check);
}

const unsigned short int		Yellow::TCPHeader::getChecksum() const
{
  return ntohs(tcp->check);
}

void					Yellow::TCPHeader::setUrgentPointer(const unsigned int urg)
{
  tcp->urg_ptr = urg;
}

const unsigned int			Yellow::TCPHeader::getUrgentPointer() const
{
  return tcp->urg_ptr;
}
