# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fivieira <fivieira@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:53:34 by fivieira          #+#    #+#              #
#    Updated: 2023/10/14 17:59:38 by fivieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = sources/so_long.c sources/map.c sources/graphics.c sources/errors.c sources/controls.c sources/check_format.c

COMMANDS:=  commands/push.c \
			commands/rev_rotate.c \
			commands/rotate.c \
			commands/sort_stacks.c \
			commands/sort_3.c \
			commands/swap.c

OBJS = ${SRC:.c=.o}



#INCLUDE = -I .

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Iheaders/

MAKE = make -C

FT_PRINTF_PATH = ft_printf

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

all:	${NAME}


$(NAME): ${OBJS} ${OBJS_GETNEXTLINE}
		$(MAKE) $(FT_PRINTF_PATH) 

		$(CC) $(CFLAGS) $(SRC) $(GETNEXTLINE) $(LIBRARY) -o $(NAME) $(FT_PRINTF)

clean:
		${MAKE} ${FT_PRINTF_PATH} clean

		${RM} ${OBJS} ${OBJS_GETNEXTLINE}


fclean: clean
		${MAKE} ${FT_PRINTF_PATH} fclean
	
		${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re