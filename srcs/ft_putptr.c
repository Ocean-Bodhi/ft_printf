#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("0x0"));
	len = 0;
	len += write(1, "0x", 2);
	len += ft_puthex((uintptr_t)ptr, 0);
	return (len);
}
/*
#include <stdio.h>

int main(void)
{
	char	*ptr;
	int	j = 0;

	ptr = "Hello 42";
	//ptr = "";
	//ptr = NULL;
	printf("Theirs PTR: %p\n", ptr);
	j = printf("%p", ptr);
	printf("j es: %i\n", j);
	printf("Mein   PTR: %p, return: %i\n", ptr, ft_putptr(ptr));
	return (0);
}
*/
