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
  };

  template<typename T>
  inline Payload<T>::Payload(void *, int len)
  {
  }

  template<typename T>
  inline Payload<T>::Payload(const Payload<T>&)
  {
  }

  template<typename T>
  inline Payload<T> & Payload<T>::operator=(const Payload<T>&)
  {
    return *this;
  }

  template<typename T>
  inline Payload<T>::~Payload()
  {
  }

  template<typename T>
  inline const T * Payload<T>::operator[](int)
  {
    return NULL;
  }

  template<typename T>
  inline int Payload<T>::getLenght()
  {
    return 0;
  }
}

#endif /* !PAYLOAD_H_ */
