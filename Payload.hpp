#ifndef PAYLOAD_H_
# define PAYLOAD_H_

namespace Yellow
{
  template <typename T>
  class Payload
  {
  public:
    Payload(void *, int len);
    Payload(const Payload<T> &);
    Payload<T> &operator=(const Payload<T> &);
    ~Payload();

    const T		*operator[](int);
    int			getLenght();
  private:
    int             len;
    unsigned char    *buff;
  };

  template<typename T>
  inline Payload<T>::Payload(void *buffer, int lenght)
    : buff(static_cast<unsigned char *>(buffer)), len(lenght)
  {
  }

  template<typename T>
  inline Payload<T>::Payload(const Payload<T> &p)
  {
    buff = p.buff;
    len = p.len;
  }

  template<typename T>
  inline Payload<T> & Payload<T>::operator=(const Payload<T> &p)
  {
    buff = p.buff;
    len = p.len;
    return *this;
  }

  template<typename T>
  inline Payload<T>::~Payload()
  {
  }

  template<typename T>
  inline const T * Payload<T>::operator[](int idx)
  {
    if (idx >= len)
      return NULL;
    return (buff[idx]);
  }

  template<typename T>
  inline int Payload<T>::getLenght()
  {
    return len;
  }
}

#endif /* !PAYLOAD_H_ */
