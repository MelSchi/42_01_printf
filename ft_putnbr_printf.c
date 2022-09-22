/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:49:35 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:55:22 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*Counts the number of digits in an integer (incl. the minus sign).*/
static int	ft_count_digits(int nb)
{
	int	counter;

	counter = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (11);
		nb = nb * -1;
		counter++;
	}
	if (nb < 10)
		return (counter + 1);
	if (nb == 10)
		return (counter + 2);
	while (nb / 10 != 0)
	{
		nb = nb / 10;
		counter++;
	}
	counter++;
	return (counter);
}

int	ft_putnbr_printf(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr_printf("-2147483648");
		return (11);
	}
	if (nb >= 0 && nb <= 9)
		ft_putchar_printf(nb + '0');
	else if (nb < 0)
	{
		ft_putchar_printf('-');
		ft_putnbr_printf(nb * -1);
	}
	else if (nb >= 10)
	{
		ft_putnbr_printf(nb / 10);
		ft_putnbr_printf(nb % 10);
	}
	return (ft_count_digits(nb));
}
