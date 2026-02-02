#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	int	len;
	long	nl;

	len = 0;
	nl = n;
	//if (n  == -2147483648)
	//	return (ft_putstr("-2147483648"));
	if (nl < 0)
	{
		len += write(1, "-", 1);
		nl = -nl;
	}
	if (nl > 9)
		len += ft_putnbr(nl / 10);
	len += ft_putchar((nl % 10) + '0');
	return (len);
}
