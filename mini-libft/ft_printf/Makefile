# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egiubell <egiubell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/14 16:25:23 by egiubell          #+#    #+#              #
#    Updated: 2023/06/14 16:25:24 by egiubell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRC:.c=.o)
NAME = libftprintf.a
LIBC = ar rcs
RM = rm -f
CC = gcc 
CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf_pointers.c ft_printf.c

$(NAME): $(OBJS)
		${LIBC} $(NAME) $(OBJS)

all: ${NAME}

clean:
		${RM} $(OBJS)

fclean: clean
		${RM} ${OBJS} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft