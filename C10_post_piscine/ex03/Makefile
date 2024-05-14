CC=cc
CFLAGS=-Wall -Wextra -Werror

SRCS=ft_display.c ft_hd.c ft_print_memory.c
NAME=ft_hexdump

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
