/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javisan2 <javisan2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 13:49:27 by javisan2          #+#    #+#             */
/*   Updated: 2026/02/03 13:49:31 by javisan2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
WRITE:
RETURN VALUES
     Upon successful completion the number of bytes which were written is
     returned.  Otherwise, a -1 is returned and the global variable errno
     is set to indicate the error.
*/

#include "../includes/ft_printf.h"

int	ft_putchar(int c)
{
	if (write (1, &c, 1) == -1)
		return (-1);
	return (1);
}
/*
# include <stdio.h>

int	main(void)
{
	int	a;
	int	b;
	int	c;

	//c = 5;
	c = 's';
	a = ft_putchar(c);
	b = write (1, &c, 1);
	printf("Mine: %i\n", a);
	printf("Theirs: %i\n", b);
	return (0);
}
*/
