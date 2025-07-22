CC =cc
CFLAGS = -g -Wall -Wextra -Werror -c
LIBFT = libft/libft.a
LIBFT_FLAGS = -Llibft -lft
CLIENT = client.c
SERVER = server.c
CLIENT_OBJ = $(CLIENT:.c=.o)
SERVER_OBJ = $(SERVER:.c=.o)
SERVER_NAME = server
CLIENT_NAME = client
NAME = wombo_combo

all: $(NAME)

$(NAME): $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
	@make -C libft

$(SERVER_NAME): $(LIBFT) $(SERVER_OBJ)
	$(CC) $(SERVER_OBJ) $(LIBFT_FLAGS) -o $@

$(CLIENT_NAME): $(LIBFT) $(CLIENT_OBJ)
	$(CC) $(CLIENT_OBJ) $(LIBFT_FLAGS) -o $@

clean:
	rm -rf $(CLIENT_OBJ) $(SERVER_OBJ)

fclean: clean
	rm -rf $(SERVER_NAME) $(CLIENT_NAME)

re: fclean all

.PHONY: all clean fclean re
