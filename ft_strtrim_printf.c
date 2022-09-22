/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_printf.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 15:23:14 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:55:31 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* checks if a character is in the set*/
static int	ft_compcharwset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

/*returns the index of the orginial string at which the first trim ends
* and the rest of the string starts. Returns 0 if there's nothing to trim.*/
static size_t	ft_trimbegin(char const *str, char const *set)
{
	size_t		i;

	i = 0;
	while (str[i] != '\0')
	{
		while (ft_compcharwset(str[i], set) == 1)
			i++;
		return (i);
	}
	return (i);
}

/*returns the index of the original string where the trim for the end starts
* returns string length if there is nothing to trim*/
static size_t	ft_trimend(char const *str, char const *set)
{
	int	str_size;

	str_size = ft_strlen(str);
	while (str_size > 0 && ft_compcharwset(str[str_size - 1], set) == 1)
		str_size--;
	return (str_size);
}

int	ft_strtrim_printf(char const *str, char const *set)
{
	size_t	input_len;
	size_t	res_len;
	size_t	start;
	size_t	stop;
	char	*res;

	if (!(str && set))
		return (0);
	input_len = ft_strlen(str);
	stop = ft_trimend(str, set);
	start = ft_trimbegin(str, set);
	res_len = (stop - start + 1);
	if (start == input_len || stop == 0)
		return (0);
	if (start == 0 && stop == input_len)
		return (input_len);
	res = (char *) ft_calloc(res_len, sizeof (char));
	if (res == NULL)
		return (0);
	ft_memcpy(res, &str[start], (res_len - 1));
	ft_putstr_printf(res);
	free(res);
	return (res_len - 1);
}
