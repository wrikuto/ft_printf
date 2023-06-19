NAME = libftprintf.a
SRCS = \
        ft_change_base.c \
        ft_count_output.c \
        ft_print_d.c \
        ft_print_u.c \
        ft_print_x.c \
        ft_printf.c \
        ft_printf_funcs.c

OBJS        =   $(SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

###################################################################################

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
