CC = cc
CFLAGS = -Wall -Wextra -Werror -g
NAME = philo
SRCS_DIR = srcs
OBJS_DIR = objs
SRCS = srcs/main.c  srcs/input_helper.c srcs/philo_list_helper.c srcs/thread_init.c \
srcs/philo_routine.c srcs/philo_routine_helper.c srcs/monitor_routine.c \
srcs/cleaner.c
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJS_DIR)/%.o, $(SRCS)) 

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
