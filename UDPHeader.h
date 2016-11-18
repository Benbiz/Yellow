#ifndef UDPHEADER_H_
# define UDPHEADER_H_

#include "ITLHeader.h"

namespace Yellow
{
  class UDPHeader : public Yellow::ITLHeader
  {
  public:
    UDPHeader(void *);
    UDPHeader(const UDPHeader &);
    UDPHeader &operator=(const UDPHeader &);
    virtual ~UDPHeader();

    virtual const unsigned char			*operator[](int) const;
    virtual const int				getLenght() const;

    const unsigned short int			getSourcePort() const;
    void					setSourcePort(const unsigned short int);

    const unsigned short int			getDestPort() const;
    void					setDestPort(const unsigned short int);

    const unsigned short int			getUDPLenght() const;
    void					setUDPLenght(const unsigned short int);

    const unsigned short int			getChecksum() const;
    void					setChecksum(const unsigned short int);
  private:
    struct udphdr				*udp;
    unsigned char				*buff;
  };
}

#endif /* !UDPHEADER_H_ */
