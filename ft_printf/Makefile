CC = cc
CFLAGS = -Wall -Wextra -Werror -Ilibft
NAME = libftprintf.a
SRCS = ft_printf.c ft_putchar_r.c ft_puthex_r.c ft_putnbr_r.c ft_putptr_r.c ft_putstr_r.c ft_putuns_r.c 
OBJS = $(SRCS:.c=.o)
LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

$(LIBFT):
	@$(MAKE) -C libft

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
