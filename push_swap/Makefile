NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_FLAGS = -Llibft - lft
LIBFT = libft/libft.a
OBJS_DIR = objs
SRCS = srcs/main.c srcs/stack_initializer.c srcs/operations.c srcs/push_swap.c
OBJS = $(patsubst srcs/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $@
	
$(LIBFT):
	@make -C libft

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< - o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
