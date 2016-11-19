#ifndef SNIFFER_H_
# define SNIFFER_H_

#include "Packet.h"

namespace Yellow
{
  class Sniffer
  {
  public:
    enum Status
    {
      Init,
      Started,
      Closed,
      Failed,
      Destroyed
    };

    Sniffer();
    ~Sniffer();

    std::shared_ptr<Yellow::Packet>		getPacket();
    Status                            getStatus() const;

    bool				start();
    void        stop();

  private:
    int					_sock;
    Status      _state;
  };
}

#endif /* !SNIFFER_H_ */
