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

		void				setVersion(unsigned int);
		unsigned int		getVesion();

		void				setHeaderLenght(unsigned int);
		unsigned int		getHeaderLenght();

		void				setTypeOfService(unsigned int);
		unsigned int		getTypeOfService();

		void				setTotalLenght(unsigned short int);
		unsigned short int	getTotalLenght();

		void				setIdentification(unsigned short);
		unsigned short int	getIndentification();

		void				setTTL(unsigned int);
		unsigned int		getTTL();

		void				setProtocol(unsigned int);
		unsigned int		getProtocol();

		void				setChecksum(unsigned short);
		unsigned short int	getChecksum();

		void				setSourceIP(const char *);
		const char			*getSourceIP();

		void				setDestIP(const char *);
		const char			*getDestinationIP();

		const void			*operator[](int) const;
	};
}

#endif /* !HEADERIP_H_*/
