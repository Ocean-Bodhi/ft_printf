/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:02 by javisan2          #+#    #+#             */
/*   Updated: 2026/02/03 13:50:05 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Puedes resolver los limits del in con long o con:

	if (n  == -2147483648)
		return (ft_putstr("-2147483648"));
*/

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	int		len;
	long	nl;

	len = 0;
	nl = n;
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
