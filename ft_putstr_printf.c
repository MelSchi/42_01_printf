/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 15:21:44 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:55:25 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_printf(char *s)
{
	int		i;

	i = 0;
	if (!s)
	{
		ft_putstr_printf("(null)");
		return (6);
	}
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_printf(s[i]);
			i++;
		}
	}
	return (i);
}
