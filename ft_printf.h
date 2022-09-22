/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 15:53:58 by mschiman          #+#    #+#             */
/*   Updated: 2021/10/25 13:52:47 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_list
{
	unsigned long	res;
	int				max;
}	t_list;

void	*ft_calloc(size_t nmemb, size_t size);
int		ft_dectohex(unsigned long input, char x_flag);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
int		ft_printf(const char *str, ...);
int		ft_put_u_nbr(unsigned int nb);
int		ft_putchar_printf(char c);
int		ft_putnbr_printf(int nb);
int		ft_putstr_printf(char *s);
size_t	ft_strlen(const char *s);
int		ft_strtrim_printf(char const *str, char const *set);
#endif
