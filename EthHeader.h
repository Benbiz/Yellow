#ifndef ETHHEADER_H_
# define ETHHEADER_H_

namespace Yellow
{
  class EthHeader
  {
  public:
    EthHeader(void *begin);
    EthHeader(const EthHeader &);
    EthHeader &operator=(const EthHeader &);
    ~EthHeader();

    typedef unsigned char*	MACAddress;
    const int				MacLenght = 6;

    void					setSource(const MACAddress);
    const MACAddress		getSource() const;

    void					setDest(const MACAddress);
    const MACAddress		getDest() const;

    const unsigned short    getProto() const;

    const unsigned char		*operator[](const int) const;
    const int				getLenght() const;
  private:
    unsigned char       *buff;
    struct ethhdr       *eth;
  };
}

#endif /* !ETHHEADER_H_ */
