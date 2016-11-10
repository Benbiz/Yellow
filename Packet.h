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

    const EthHeader                                 &getEthHeader() const;
    const IPHeader                                  &getIPHeader() const;

    const std::shared_ptr<Yellow::ITLHeader>        getTLHeader() const;

    template <typename T>
    const Payload<T>                                getPayload() const;
    template <typename T>
    void                                            setPayload(const Payload<T> &);

    std::chrono::high_resolution_clock::time_point  &getTimePoint();
    void                                            setTimePoint(std::chrono::high_resolution_clock::time_point &tp);

    const unsigned char                             *operator[](int) const;
    const int                                       getLenght() const;
  private:
    unsigned char                                   *buff;
    int                                             len;
    EthHeader                                       eth;
    IPHeader                                        ip;
    std::shared_ptr<ITLHeader>                      tl;
    std::chrono::high_resolution_clock::time_point  tp;
  };

  template<typename T>
  inline const Payload<T> Packet::getPayload() const
  {
    int   headerlen;

    headerlen = eth.getLenght() + ip.getHeaderLenght() + tl->getLenght();
    return Payload<T>(buff + headerlen, len - headerlen);
  }

  template<typename T>
  inline void Packet::setPayload(const Payload<T>&)
  {
  }
}

#endif /* !PACKET_H_ */
