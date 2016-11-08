#include "stdafx.h"
#include "Sniffer.h"

Yellow::Sniffer::Sniffer()
{
}

Yellow::Sniffer::~Sniffer()
{
}

std::shared_ptr<Yellow::Packet> Yellow::Sniffer::getPacket()
{
	return std::shared_ptr<Yellow::Packet>();
}

bool Yellow::Sniffer::start()
{
	return false;
}
