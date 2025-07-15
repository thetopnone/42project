NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBFT_FLAGS = -Llibft -lft
LIBFT = libft/libft.a
OBJS_DIR = objs
SRCS = srcs/main.c srcs/stack_init.c srcs/chunking_helper.c \
srcs/helper.c srcs/push.c srcs/reverse_rotate.c srcs/rotate.c srcs/sorter.c \
srcs/sorter_helper_1.c srcs/sorter_helper_2.c srcs/sorter_helper_3.c \
srcs/sorter_helper_4.c srcs/swap.c srcs/chunking.c srcs/stack_helper.c
OBJS = $(patsubst srcs/%.c, $(OBJS_DIR)/%.o, $(SRCS))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_FLAGS) -o $@
	
$(LIBFT):
	@make -C libft

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
