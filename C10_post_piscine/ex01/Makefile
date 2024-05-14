CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_display.c ft_cat.c
NAME=ft_cat

OBJS=${SRCS:.c=.o}

%.o: %.c ${SRCS}
	${CC} ${CFLAGS} -c $< -o $@

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
	rm ${OBJS}

fclean:
	rm ${NAME}

.PHONY: all clean fclean
