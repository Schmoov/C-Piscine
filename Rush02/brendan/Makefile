# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/24 18:41:32 by bvictoir          #+#    #+#              #
#    Updated: 2024/02/25 09:56:56 by bvictoir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= write_3_dgt.c

PRE		= ./srcs/

SRCS	= ${addprefix ${PRE}, ${SRC}}

OBJS	= ${SRCS:.c=.p}

HEAD	= ./includes/

NAME	= rush-02

CC		= cc

AR		= ar rc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror


all:		${NAME}

.c.o:
			${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re
