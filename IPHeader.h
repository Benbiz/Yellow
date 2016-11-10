#ifndef HEADERIP_H_
# define HEADERIP_H_

namespace Yellow
{
  class IPHeader
  {
  public:
    IPHeader(void *begin);
    IPHeader(const IPHeader &);
    IPHeader &operator=(const IPHeader &);
    ~IPHeader();

    void                        setVersion(unsigned int);
    const unsigned int          getVesion() const;

    void                        setHeaderLenght(unsigned int);
    const unsigned int          getHeaderLenght() const;

    void                        setTypeOfService(unsigned int);
    const unsigned int          getTypeOfService() const;

    void                        setTotalLenght(unsigned short int);
    const unsigned short int	getTotalLenght() const;

    void                        setIdentification(unsigned short);
    const unsigned short int	getIndentification() const;

    void                        setTTL(unsigned int);
    const unsigned int          getTTL() const;

    void                        setProtocol(unsigned int);
    const unsigned int          getProtocol() const;

    void                        setChecksum(unsigned short);
    const unsigned short int	getChecksum() const;

    void                        setSourceIP(const std::string &addr);
    const std::string           &getSourceIP() const;

    void                        setDestIP(const std::string &addr);
    const std::string           &getDestinationIP() const;

    const unsigned char         *operator[](int) const;
  private:
    unsigned char               *buff;
    struct iphdr                *ip;
    std::string                 source;
    std::string                 dest;
    struct sockaddr_in          sourceaddr;
    struct sockaddr_in          destaddr;
  };
}

#endif /* !HEADERIP_H_*/
