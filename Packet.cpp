#include "stdafx.h"
#include "Packet.h"

Yellow::Packet::Packet(void * buff, int len)
	: eth(buff), ip(buff)
{
}

Yellow::Packet::~Packet()
{
}

const Yellow::EthHeader						&Yellow::Packet::getEthHeader() const
{
	return eth;
}

const Yellow::IPHeader						&Yellow::Packet::getIPHeader() const
{
	return ip;
}

const std::shared_ptr<Yellow::ITLHeader>	Yellow::Packet::getTLHeader() const
{
	return std::shared_ptr<ITLHeader>();
}

const void									*Yellow::Packet::operator[](int) const
{
	return nullptr;
}
