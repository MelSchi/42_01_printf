/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_u_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:49:35 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:55:12 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Counts the number of digits in an unsigned integer.*/
static int	ft_count_digits(unsigned int nb)
{
	int	counter;

	counter = 0;
	if (nb < 10)
		return (1);
	if (nb == 10)
		return (2);
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		counter++;
	}
	counter++;
	return (counter);
}

int	ft_put_u_nbr(unsigned int nb)
{
	if (nb <= 9)
		ft_putchar_printf(nb + '0');
	else if (nb >= 10)
	{
		ft_putnbr_printf(nb / 10);
		ft_putnbr_printf(nb % 10);
	}
	return (ft_count_digits(nb));
}
