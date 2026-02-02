#include "../includes/ft_printf.h"

int	ft_puthex(uintptr_t n, int upper)
{
	int	len;
	char	*hex;

	len = 0;
	if (upper)
		hex = "0123456789ABCDEF";
	else
		hex = "0123456789abcdef";
	if (n == 0)
	{
		len += ft_putchar('0');
		return (len);
	}
	if (n >= 16)
		len += ft_puthex(n / 16, upper);
	len += ft_putchar(hex[n % 16]);
	return (len);
}
