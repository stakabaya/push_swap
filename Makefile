SRCS =  ./src/push_swap.c\
		./src/error.c ./src/comlist_check.c ./src/end_program.c \
		./src/listoparation/opcomlst_oparation.c ./src/listoparation/stack_oparation.c \
		./src/listoparation/sa.c ./src/listoparation/ra_pa.c \
		./src/sort/sort.c ./src/sort/cases.c \
		./src/sort/three_args.c ./src/sort/over_six.c


OBJS    = $(SRCS:.c=.o)
NAME    = push_swap
CC      = gcc
RM      = rm -f
CFLAGS = -Wall -Wextra -Werror -I include -g  -fsanitize=address

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) ./libft/libft.a -o $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re .c.o
