# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: parden <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/29 15:00:59 by parden            #+#    #+#              #
#    Updated: 2024/02/29 16:45:33 by parden           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
NAME=libft.a

CFLAGS= -Wall -Wextra -Werror

INC_DIR=./includes/
INC_NAME=ft.h
HEADERS= ${addprefix ${INC_DIR},${INC_NAME}}

SRC_DIR=./srcs/
SRC_NAME=ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c
SRCS=${addprefix ${SRC_DIR},${SRC_NAME}}

OBJS=${SRCS:.c=.o}

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	ar rc ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
