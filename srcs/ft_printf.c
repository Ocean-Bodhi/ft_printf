/*
Desciption:
ft_printf(),
a function that will mimic the original printf()
You have to recode the printf() function from libc.
The prototype of ft_printf() is:
int ft_printf(const char *, ...);
Here are the requirements:
• Do not implement the buffer management of the original printf().
• Your function has to handle the following conversions: cspdiuxX%
• Your function will be compared against the original printf().

You have to implement the following conversions:
• %c Prints a single character.
• %s Prints a string (as defined by the common C convention).
• %p The void * pointer argument has to be printed in hexadecimal format.
• %d Prints a decimal (base 10) number.
• %i Prints an integer in base 10.
• %u Prints an unsigned decimal (base 10) number.
• %x Prints a number in hexadecimal (base 16) lowercase format.
• %X Prints a number in hexadecimal (base 16) uppercase format.
• %% Prints a percent sign.

SYNOPSIS:
#include <stdarg.h>

   	void	va_start(va_list ap, last);
	type	va_arg(va_list ap, type);
	void	va_end(va_list ap);
The first use of the va_arg() macro after that of the va_start()
     macro returns the argument after last.  Successive invocations
     return the values of the remaining arguments.
*/

#include "../includes/ft_printf.h"

static int	ft_conversion(const char type, va_list vargs)
{
	if (type == 'c' )
		return (ft_putchar(va_arg(vargs, int)));
	else if (type == 's')
		return (ft_putstr(va_arg(vargs, char *)));
	else if (type == 'p')
		return (ft_putptr(va_arg(vargs, void *)));
	else if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(vargs, int)));
	else if (type == 'u')
		return (ft_putunsg(va_arg(vargs, unsigned int)));
	else if (type == 'x')
		return (ft_puthex(va_arg(vargs, unsigned int), 0));
	else if (type == 'X')
		return (ft_puthex(va_arg(vargs, unsigned int), 1));
	else if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

static int	ft_check(const char *str, va_list vargs, int i, int len)
{
	int	result;

	if (!str) // Es necesario? Y (!vargs)? y los int?
		return (-1);
	result = 0;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			result = ft_conversion(str[++i], vargs);
			if (result == -1)
				return (-1);
			len = (len + result);
		}
		else
		{
			if (write (1, &str[i], 1) == -1)
				return (-1);
			len++;
		}
		i++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int	len;
	va_list	vargs;

	va_start(vargs, format);
	len = ft_check(format, vargs, 0, 0);
	va_end(vargs);
	return (len);
}
/*
# include <stdio.h>

int	main(void)
{
	int	i;
	char	c;
	//char	s[] = "Hello 42";
	//unsigned int	ui;
	//char	c2;

	i = 5;
	c = 'A';
	//c2 = '%';
	//ui = -12;

	ft_printf("Mine is: i = %i, c = %c\n", i, c);
	printf("Theirs is: i = %i, c = %c\n", i, c);

	ft_printf("Mine is: i = %i, c = %c, str = %s, ptr = %p, ui = %u, \
	x = %x,'X' = %X, '%' = %%\n", i, c, s, *s, ui, ui, ui, c2);
	//printf("Theirs is: i = %i, c = %c, str = %s, ui = %u, \
	x = %x,'X' = %X, '%' = %%\n", i, c, s, *s, ui, ui, ui, c2);
	return (0);
}
*/
