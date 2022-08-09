# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cleibeng <cleibeng@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/03 14:42:47 by cleibeng          #+#    #+#              #
#    Updated: 2022/08/09 18:11:27 by cleibeng         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c\
		utils/sort_large.c\
		utils/sort_small.c\
		utils/create_list.c\
		utils/operations_a.c\
		utils/operations_b.c\
		utils/parsing.c\
		utils/utils.c\

OBJS = ${SRCS:.c=.o}

DEP = ${SRCS:.c=.d}

CC = cc

CFLAGS = -g -Wall -Wextra -Werror -MMD

RM = rm -rf

LIBFT = Libft/libft.a

all: ${NAME}

%.o:%.c
	${CC} ${CFLAGS} -I Libft -c -o $@ $<

${NAME}: ${OBJS} ${LIBFT}
	${CC} -g ${OBJS} -o ${NAME} -LLibft -lft

${LIBFT}:
	make -C Libft

clean:
	${RM} ${OBJS} ${DEP}
	make clean -C Libft

fclean: clean
		${RM} ${NAME}
		make fclean -C Libft

re:	fclean all

-include ${DEP}

.PHONY: all clean fclean re
