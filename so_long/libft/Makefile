# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 18:55:58 by akonstan          #+#    #+#              #
#    Updated: 2024/12/05 20:33:28 by akonstan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c get_next_line/get_next_line.c ft_printf/ft_printf.c ft_printf/ft_putchar_r.c ft_printf/ft_puthex_r.c ft_printf/ft_putnbr_r.c ft_printf/ft_putptr_r.c ft_printf/ft_putstr_r.c ft_printf/ft_putuns_r.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

# Creates the final file

$(NAME): $(OBJS)
	ar rcs $@ $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
