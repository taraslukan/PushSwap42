# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlukan <tlukan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 12:18:17 by tlukan            #+#    #+#              #
#    Updated: 2024/05/31 15:36:36 by tlukan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_putchr.c ft_putnbr.c ft_putnbrbas.c ft_putnbrbasp.c \
ft_putnbruns.c

OUT = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra
 
.c.o:
		@${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OUT)
		@ar rcs $(NAME) $(OUT)

all:	$(NAME)

clean:
		@rm -f $(OUT) $(BOUT)

fclean: clean
		@rm -f $(NAME)

re: 	fclean all

r:
	@make -s
	@gcc main.c libftprintf.a
	@./a.out
