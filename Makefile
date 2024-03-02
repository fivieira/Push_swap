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

SRC = source/handle_error.c source/push_swap.c source/init_stack_a_b.c source/init_stack_b_a.c source/stack_unit.c source/stack_utils.c source/split.c

COMMANDS:=  source/commands/push.c \
			source/commands/rev_rotate.c \
			source/commands/rotate.c \
			source/commands/sort_stacks.c \
			source/commands/sort_3.c \
			source/commands/swap.c 

OBJS = ${SRC:.c=.o}

OBJS_COMMANDS = ${COMMANDS:.c=.o}

#INCLUDE = -I .

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -Iincludes/

MAKE = make -C

FT_PRINTF_PATH = ft_printf

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

all:	${NAME}


$(NAME): ${OBJS} ${OBJS_COMMANDS}
		$(MAKE) $(FT_PRINTF_PATH) 
		$(CC) $(CFLAGS) $(SRC) $(COMMANDS) -o $(NAME) $(FT_PRINTF)

clean:
		${MAKE} ${FT_PRINTF_PATH} clean
		${RM} ${OBJS} ${OBJS_COMMANDS}


fclean: clean
		${MAKE} ${FT_PRINTF_PATH} fclean
	
		${RM} ${NAME}


re: fclean all

.PHONY: all clean fclean re