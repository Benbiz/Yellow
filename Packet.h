#ifndef PACKET_H_
# define PACKET_H_

#include "Packet.h"
#include "Payload.hpp"
#include "EthHeader.h"
#include "IPHeader.h"
#include "ITLHeader.h"

namespace Yellow
{
  class Packet
  {
  public:
    Packet(void *buff, int len);
    ~Packet();

    const EthHeader                           &getEthHeader() const;
    const IPHeader                            &getIPHeader() const;

    const std::shared_ptr<Yellow::ITLHeader>  getTLHeader() const;

    template <typename T>
    const Payload<T>                        	getPayload() const;
    template <typename T>
    void                                      setPayload(const Payload<T> &);

    const unsigned char                       *operator[](int) const;

  private:
    unsigned char               *buff;
    int                         len;
    EthHeader                   eth;
    IPHeader                    ip;
    std::shared_ptr<ITLHeader>	tl;
  };

  template<typename T>
  inline const Payload<T> Packet::getPayload() const
  {
    return Payload<T>(buff);
  }

  template<typename T>
  inline void Packet::setPayload(const Payload<T>&)
  {
  }
}

#endif /* !PACKET_H_ */
