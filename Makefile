SERVER_SRCS	= server.c 
CLIENT_SRCS	= client.c
LIBFT_SRCS  = libft/ft_atoi.c

CC			= gcc
CC_FLAGS	= -Wall -Werror -Wextra

PRINTF_DIR  = printf
LIBFT_DIR   = libft

SERVER_OBJS	= ${SERVER_SRCS:.c=.o} libft/ft_atoi.o ${PRINTF_DIR}/libftprintf.a
CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o} libft/ft_atoi.o ${PRINTF_DIR}/libftprintf.a

all: printf server client

printf:
	@make -C ${PRINTF_DIR}

server: ${SERVER_OBJS}
	${CC} ${SERVER_OBJS} ${CC_FLAGS} -o server

client: ${CLIENT_OBJS}
	${CC} ${CLIENT_OBJS} ${CC_FLAGS} -o client

clean:
	rm -f ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}
	rm -f libft/*.o
	@make -C ${PRINTF_DIR} -f Makefile clean

fclean: clean
	rm -f client server
	@make -C ${PRINTF_DIR} -f Makefile fclean

re: fclean all

.PHONY: all printf server client clean fclean re