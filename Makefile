NAME	=	philo

SRCS	=	./src/main.c \
			./src/ft_atoi.c \
			./src/philo.c \
			./src/mutex.c \
			./src/track.c \
			./src/time.c \
			./src/utils.c



CC		= cc
INC	=	../inc/
# FLAGS	= -Wall -Wextra -Werror -fsanitize=thread -g -I$(INC)
FLAGS	= -Wall -Wextra -Werror -I$(INC)
RM		= rm -rf

OBJS_PATH = ./objs/
SRCS_PATH = ./src/
# OBJS = ${SRCS:%.c=%.o}

SRCS_FILES =	main.c \
			ft_atoi.c \
			philo.c \
			mutex.c \
			track.c \
			time.c \
			utils.c

OBJS = $(addprefix $(OBJS_PATH), $(SRCS_FILES:.c=.o))

$(OBJS_PATH):
	mkdir -p $@



all:		$(NAME)
 
$(NAME): $(OBJS_PATH) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

$(OBJS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
			rm -f $(OBJS)

fclean:		clean
			rm -f $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re
