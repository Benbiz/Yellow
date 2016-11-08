#include "stdafx.h"
#include <iostream>
#include "EthHeader.h"

Yellow::EthHeader::EthHeader(void * begin)
{
}

Yellow::EthHeader::EthHeader(const EthHeader &)
{
}

Yellow::EthHeader & Yellow::EthHeader::operator=(const EthHeader &)
{
	return (*this);
}

Yellow::EthHeader::~EthHeader()
{
}

void Yellow::EthHeader::setSource(const MACAddress)
{
}

const Yellow::EthHeader::MACAddress Yellow::EthHeader::getSource() const
{
	return MACAddress();
}

void Yellow::EthHeader::setDest(const MACAddress)
{
}

const Yellow::EthHeader::MACAddress Yellow::EthHeader::getDest() const
{
	return MACAddress();
}

unsigned short int Yellow::EthHeader::getProto()
{
	return 0;
}

void * Yellow::EthHeader::operator[](const int) const
{
	return nullptr;
}

const int Yellow::EthHeader::getLenght() const
{
	return 0;
}
