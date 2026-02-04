/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:16 by javisan2          #+#    #+#             */
/*   Updated: 2026/02/03 13:50:18 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	len;

	if (!ptr)
		return (ft_putstr("(nil)"));
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
