#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	n = n + '0';
	if (write(1, &n, 1) == -1)
		return (-1);
	return (1);
}
