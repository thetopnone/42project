# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akonstan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/30 17:50:16 by akonstan          #+#    #+#              #
#    Updated: 2025/06/30 17:50:18 by akonstan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus
CC = cc 
CFLAGS = -g -Wall -Wextra -Werror
MLXFLAGS = -Lminilibx-linux -lmlx -Imlx_linux
LIBFTFLAGS = -Llibft -lft
TRAILFLAGS = -lm -lz -lXext -lX11
LIBFT = libft/libft.a
MLX = minilibx-linux/libmlx.a
OBJS_BONUS_DIR = objs_bonus
OBJS_DIR = objs
SRCS = srcs/initializer.c srcs/read_map.c srcs/validate_map.c srcs/main.c \
srcs/error_handler.c srcs/input_handling.c srcs/cleanup_mlx.c srcs/renderer.c
SRCS_BONUS = srcs_bonus/initializer_bonus.c srcs_bonus/read_map_bonus.c \
srcs_bonus/validate_map_bonus.c srcs_bonus/main_bonus.c \
srcs_bonus/error_handler_bonus.c srcs_bonus/input_handling_bonus.c \
srcs_bonus/cleanup_mlx_bonus.c srcs_bonus/renderer_bonus.c\
srcs_bonus/renderer_helper_bonus.c srcs_bonus/init_helper_bonus.c\
srcs_bonus/close_program_bonus.c srcs_bonus/renderer_helper2_bonus.c
OBJS = $(patsubst srcs/%.c, $(OBJS_DIR)/%.o, $(SRCS))
OBJS_BONUS = $(patsubst srcs_bonus/%.c, $(OBJS_BONUS_DIR)/%.o, $(SRCS_BONUS))

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME) $(TRAILFLAGS)

$(LIBFT):
	@$(MAKE) -C libft

$(MLX):	
	@$(MAKE) -C minilibx-linux

$(OBJS_DIR)/%.o: srcs/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@
	
$(OBJS_BONUS_DIR)/%.o: srcs_bonus/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I/usr/include -Iminilibx-linux -c $< -o $@

clean:
	rm -rf $(OBJS_DIR) $(OBJS_BONUS_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)

re: fclean all

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(MLX) $(LIBFT) $(OBJS_BONUS) 
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(MLXFLAGS) $(LIBFTFLAGS) -o $(NAME_BONUS) \
	$(TRAILFLAGS)
	
.PHONY: fclean clean re all bonus
