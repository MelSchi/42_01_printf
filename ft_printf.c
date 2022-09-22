/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 14:20:17 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:55:09 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_printf_convert(const char *str, va_list args, int strlen, int i)
{
	while (str[i] != '\0')
	{
		if (str[i] != '%')
			strlen += ft_putchar_printf(str[i]);
		else
		{
			i++;
			if (str[i] == 'x' || str[i] == 'X' || str[i] == 'p')
				strlen += ft_dectohex(va_arg(args, unsigned long), str[i]);
			else if (str[i] == 'i' || str[i] == 'd')
				strlen += ft_putnbr_printf(va_arg(args, int));
			else if (str[i] == 'u')
				strlen += ft_put_u_nbr(va_arg(args, unsigned int));
			else if (str[i] == 'c')
				strlen += ft_putchar_printf((char) va_arg(args, int));
			else if (str[i] == 's')
				strlen += ft_putstr_printf(va_arg(args, char *));
			else if (str[i] == '%')
				strlen += ft_putchar_printf('%');
		}
		i++;
	}
	return (strlen);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	int		strlen;
	int		print_len;

	i = 0;
	strlen = 0;
	if (!str)
		return (-1);
	va_start(args, str);
	print_len = ft_printf_convert(str, args, strlen, i);
	va_end(args);
	return (print_len);
}
