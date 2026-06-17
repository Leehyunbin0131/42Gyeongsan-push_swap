NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c \
	instructions.c \
	operations_reverse_rotate.c \
	operations_rotate.c \
	operations_swap_push.c \
	parse_utils.c \
	sort_selection.c \
	stack_init.c \
	stack_utils.c \
	libft_utlis.c \
	ft_split.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
