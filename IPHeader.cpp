#include "stdafx.h"
#include "IPHeader.h"

Yellow::IPHeader::IPHeader(void * begin)
{
}

Yellow::IPHeader::IPHeader(const IPHeader &)
{
}

Yellow::IPHeader & Yellow::IPHeader::operator=(const IPHeader &ip)
{
	return *this;
}

Yellow::IPHeader::~IPHeader()
{
}

void Yellow::IPHeader::setVersion(unsigned int)
{
}

unsigned int Yellow::IPHeader::getVesion()
{
	return 0;
}

void Yellow::IPHeader::setHeaderLenght(unsigned int)
{
}

unsigned int Yellow::IPHeader::getHeaderLenght()
{
	return 0;
}

void Yellow::IPHeader::setTypeOfService(unsigned int)
{
}

unsigned int Yellow::IPHeader::getTypeOfService()
{
	return 0;
}

void Yellow::IPHeader::setTotalLenght(unsigned short int)
{
}

unsigned short int Yellow::IPHeader::getTotalLenght()
{
	return 0;
}

void Yellow::IPHeader::setIdentification(unsigned short int)
{
}

unsigned short Yellow::IPHeader::getIndentification()
{
	return 0;
}

void Yellow::IPHeader::setTTL(unsigned int)
{
}

unsigned int Yellow::IPHeader::getTTL()
{
	return 0;
}

void Yellow::IPHeader::setProtocol(unsigned int)
{
}

unsigned int Yellow::IPHeader::getProtocol()
{
	return 0;
}

void Yellow::IPHeader::setChecksum(unsigned short int)
{
}

unsigned short int Yellow::IPHeader::getChecksum()
{
	return 0;
}

void Yellow::IPHeader::setSourceIP(const char *)
{
}

const char * Yellow::IPHeader::getSourceIP()
{
	return nullptr;
}

void Yellow::IPHeader::setDestIP(const char *)
{
}

const char * Yellow::IPHeader::getDestinationIP()
{
	return nullptr;
}

const void * Yellow::IPHeader::operator[](int) const
{
	return nullptr;
}
