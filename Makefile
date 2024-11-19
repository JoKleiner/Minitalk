SERVER_SRCS	= server.c 
CLIENT_SRCS	= client.c
LIBFT_SRCS  = libft/ft_atoi.c

CC			= gcc 
CC_FLAGS	= -Wall -Werror -Wextra

SERVER_OBJS	= ${SERVER_SRCS:.c=.o} libft/ft_atoi.o
CLIENT_OBJS	= ${CLIENT_SRCS:.c=.o} libft/ft_atoi.o

all: server client

server: ${SERVER_OBJS}
	${CC} ${SERVER_OBJS} ${CC_FLAGS} -o server

client: ${CLIENT_OBJS}
	${CC} ${CLIENT_OBJS} ${CC_FLAGS} -o client

clean:
	rm -f ${SERVER_OBJS} ${CLIENT_OBJS}
	@make clean -C ${LIBFT_DIR} # Clean libft directory

fclean: clean
	rm -f client server
	@make fclean -C ${LIBFT_DIR} # Force fclean in libft

re: fclean all

.PHONY: all clean fclean re
