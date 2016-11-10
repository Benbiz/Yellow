#ifndef TCPHEADER_H_
# define TCPHEADER_H_

#include "ITLHeader.h"

namespace Yellow
{
  class TCPHeader : public Yellow::ITLHeader
  {
  public:
    TCPHeader(void *);
    TCPHeader(const TCPHeader &);
    TCPHeader &operator=(const TCPHeader &);
    virtual ~TCPHeader();

    virtual const unsigned char     *operator[](int) const;
    virtual const int               getLenght() const;

    void                      setSourcePort(const unsigned short int);
    const unsigned short int	getSourcePort() const;

    void                      setDestPort(const unsigned short int);
    const unsigned short int	getDestPort() const;

    void                      setSequenceNumber(const unsigned short int);
    const unsigned short int	getSequenceNumber() const;

    void                      setAcknowledgeNumber(const unsigned short int);
    const unsigned short int	getAcknowledgeNumber() const;

    void                      setHeaderLenght(const unsigned int);
    const unsigned int        getHeaderLenght() const;

    void                      setUrgentFlag(const unsigned int);
    const unsigned int        getUrgentFlag() const;

    void                      setAcknowledgementFlag(const unsigned int);
    const unsigned int        getAcknowledgementFlag() const;

    void                      setPushFlag(const unsigned int);
    const unsigned int        getPushFlag() const;

    void                      setResetFlag(const unsigned int);
    const unsigned int        getResetFlag() const;

    void                      setSynchroniseFlag(const unsigned int);
    const unsigned int        getSynchroniseFlag() const;

    void                      setFinishFlag(const unsigned int);
    const unsigned int        getFinishFlag() const;

    void                      setWindow(const unsigned short int);
    const unsigned short int	getWindow() const;

    void                      seChecksum(const unsigned short int);
    const unsigned short int	getChecksum() const;

    void                      setUrgentPointer(const unsigned int);
    const unsigned int        getUrgentPointer() const;
  private:
    unsigned char       *buff;
    struct tcphdr       *tcp;
  };
}

#endif /* !TCPHEADER_H_ */
