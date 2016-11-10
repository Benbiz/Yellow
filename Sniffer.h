#ifndef SNIFFER_H_
# define SNIFFER_H_

#include "Packet.h"

namespace Yellow
{
  class Sniffer
  {
  public:
    Sniffer();
    ~Sniffer();

    std::shared_ptr<Yellow::Packet>		getPacket();

    bool				start();
  private:
    int					_sock;
  };
}

#endif /* !SNIFFER_H_ */
