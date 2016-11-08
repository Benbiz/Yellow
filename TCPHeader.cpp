#include "stdafx.h"
#include "TCPHeader.h"

Yellow::TCPHeader::TCPHeader(void *)
{
}

Yellow::TCPHeader::~TCPHeader()
{
}

void					*Yellow::TCPHeader::operator[](int) const
{
	return nullptr;
}

const int				Yellow::TCPHeader::getLenght() const
{
	return 0;
}

void					Yellow::TCPHeader::setSourcePort(const unsigned short int)
{
}

unsigned short int		Yellow::TCPHeader::getSourcePort() const
{
	return 0;
}

void					Yellow::TCPHeader::setDestPort(const unsigned short int)
{
}

unsigned short int		Yellow::TCPHeader::getDestPort() const
{
	return 0;
}

void					Yellow::TCPHeader::setSequenceNumber(const unsigned short int)
{
}

unsigned short int		Yellow::TCPHeader::getSequenceNumber() const
{
	return 0;
}

void					Yellow::TCPHeader::setAcknowledgeNumber(const unsigned short int)
{
}

unsigned short int		Yellow::TCPHeader::getAcknowledgeNumber() const
{
	return 0;
}

void					Yellow::TCPHeader::setHeaderLenght(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getHeaderLenght() const
{
	return 0;
}

void					Yellow::TCPHeader::setUrgentFlag(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getUrgentFlag() const
{
	return 0;
}

void					Yellow::TCPHeader::setAcknowledgementFlag(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getAcknowledgementFlag() const
{
	return 0;
}

void					Yellow::TCPHeader::setPushFlag(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getPushFlag() const
{
	return 0;
}

void					Yellow::TCPHeader::setSynchroniseFlag(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getSynchroniseFlag() const
{
	return 0;
}

void					Yellow::TCPHeader::setFinishFlag(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getFinishFlag() const
{
	return 0;
}

void					Yellow::TCPHeader::setWindow(const unsigned short int)
{
}

unsigned short int		Yellow::TCPHeader::getWindow() const
{
	return 0;
}

void					Yellow::TCPHeader::seChecksum(const unsigned short int)
{
}

unsigned short int		Yellow::TCPHeader::getChecksum() const
{
	return 0;
}

void					Yellow::TCPHeader::setUrgentPointer(const unsigned int)
{
}

unsigned int			Yellow::TCPHeader::getUrgentPointer() const
{
	return 0;
}
