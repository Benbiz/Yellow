#ifndef ITLHEADER_H_
# define ITLHEADER_H_

namespace Yellow
{
	class ITLHeader
	{
	public:
		virtual ~ITLHeader() {}

		virtual void		*operator[](int) const = 0;
		virtual const int	getLenght() const = 0;
	};
}

#endif /* !ITLHEADER_H_ */