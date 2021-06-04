NAME = push_swap

CC = gcc

ERR_FLAGS = -Wall -Wextra #-Werror

DEBUG_FLAGS = -g -fsanitize=address

DEP_FLAGS = -I. -Ilibft

LIBFT = libft/libft.a

LIB = push_swap.h

SRC = ${wildcard *.c}

all: libft push_swap

libft:
	cd libft && ${MAKE}

push_swap: ${LIB} ${SRC}
	${CC} ${ERR_FLAGS} ${DEBUG_FLAGS} ${DEP_FLAGS} ${SRC} ${LIBFT} -o $@

clean:
	rm -rf push_swap *.dSYM

fclean: clean
	cd libft && ${MAKE} fclean

re: fclean all

.PHONY: all clean fclean re libft
