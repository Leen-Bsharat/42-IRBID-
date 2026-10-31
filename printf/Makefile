NAME		= libftprintf.a

CC		= cc
CFLAGS		= -Wall -Wextra -Werror

AR		= ar rcs
RM		= rm -f

SRCS		= ft_printf.c \
		  ft_putchar.c \
		  ft_print_string.c \
		  ft_print_digit.c \
		  ft_print_unsigned_int.c \
		  ft_print_hex.c \
		  ft_print_ptr.c \
		  ft_strlen.c \
		  ft_putnbr_fd.c

OBJS		= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
