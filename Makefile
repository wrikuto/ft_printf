NAME = libftprintf.a
SRCS = \
		ft_change_base.c \
        ft_count_output.c \
        ft_printf.c \
        ft_putstr_count.c \
        ft_treat_char.c \
        ft_treat_hexa.c \
        ft_treat_int.c \
        ft_treat_point.c \
        ft_treat_something.c \
        ft_treat_string.c \
        ft_treat_uint.c

LIBDT_SRCS = $(addprefix libft/, \
        ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
        ft_isprint.c ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
        ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
        ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c \
        ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
        )
OBJS        =   $(SRCS:.c=.o)
LIBFT_OBJS  =   $(LIBFT_SRCS:.c=.o)
CC = cc
CFLAGS = -Wall -Wextra -Werror

###################################################################################

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_OBJS)
	ar rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

$(OBJS): %.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(LIBFT_OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
