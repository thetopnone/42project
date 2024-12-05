# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akonstan <akonstan@student.42warsaw.pl>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/05 18:55:58 by akonstan          #+#    #+#              #
#    Updated: 2024/12/05 20:03:32 by akonstan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS: %.c =%.o)

all: $(NAME)

$(NAME): $(OBJS) #Creates the final file
	$(CC) $(CFLAGS) -o $@ $(OBJS)

%.o: %.c #Compiles .c files to create .o files
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -


fclean:

re:
