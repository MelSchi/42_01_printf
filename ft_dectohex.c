/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 16:33:38 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:55:02 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	zero_input(char flag)
{
	if (flag == 'p')
	{
		ft_putstr_printf("0x0");
		return (3);
	}
	ft_putstr_printf("0");
	return (1);
}

static int	conv_input(unsigned long input, char flag, char *conv, char *hex)
{
	struct s_list	var;

	var.max = 18;
	while (input != 0)
	{
		var.res = input % 16;
		input = input / 16;
		if (flag == 'x' || flag == 'p')
			hex[var.max] = conv[var.res];
		else if (flag == 'X')
			hex[var.max] = conv[(var.res + 16)];
		var.max--;
		if ((flag == 'x' || flag == 'X') && var.max == 10)
		{
			while (hex[var.max + 1] != '\0' && hex[var.max + 1] == '0')
			{
				hex[var.max] = 'x';
				var.max++;
			}
			break ;
		}
	}
	if (flag == 'p')
		hex[var.max - 1] = '0';
	return (ft_strtrim_printf(hex, "x"));
}

/*Turns a max lli into a hex-string and adds 0x if the pointer flag is given*/
int	ft_dectohex(unsigned long input, char flag)
{
	char			hex[20];
	char			*conv;

	conv = "0123456789abcdef0123456789ABCDEF";
	ft_memset(hex, 'x', 19);
	hex[19] = '\0';
	if (flag == 'x' || flag == 'X')
		input = (unsigned int) input;
	if (input == 0)
		return (zero_input(flag));
	return (conv_input(input, flag, conv, hex));
}
