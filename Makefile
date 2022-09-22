# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/04 12:21:28 by mschiman          #+#    #+#              #
#    Updated: 2021/10/25 13:56:48 by mschiman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =	ft_calloc.c \
		ft_dectohex.c \
		ft_memcpy.c \
		ft_memset.c \
		ft_putchar_printf.c \
		ft_putstr_printf.c \
		ft_putnbr_printf.c \
		ft_put_u_nbr.c \
		ft_strlen.c \
		ft_strtrim_printf.c \
		ft_printf.c \

OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -c
CC =	gcc
RM = rm -f

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
$(OBJ): $(SRC)
	$(CC) $(CFLAGS) $(SRC)

clean:
	$(RM) $(OBJ) a.out

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re