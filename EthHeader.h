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

		unsigned short			getProto();

		void					*operator[](const int) const;
		const int				getLenght() const;
	};
}

#endif /* !ETHHEADER_H_ */
