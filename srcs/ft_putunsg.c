/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:50:43 by javisan2          #+#    #+#             */
/*   Updated: 2026/02/03 13:50:45 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putunsg(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunsg(n / 10);
	len += ft_putchar((n % 10) + '0');
	return (len);
}
