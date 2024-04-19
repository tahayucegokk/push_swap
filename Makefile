NAME = push_swap
CC = gcc -g

CFLAGS = -Wall -Wextra -Werror

CFILES_1 = push_swap.c

CFILES_2 = basic_sorts.c \
			free.c \
			quick_sort.c \
			rules1.c \
			rules2.c \
			rules3.c \
			sorter.c \
			sort_func.c \
			utils.c \
			utils2.c \
			utils3.c


OBJS_1 = $(CFILES_1:.c=.o)

OBJS_2 = $(CFILES_2:.c=.o)


$(NAME): $(OBJS_1) $(OBJS_2)
	@$(CC) $(CFLAGS) $(OBJS_1) $(OBJS_2) $(LIBFT) -o $(NAME)

all: $(NAME)

clean: 
		@rm -f $(OBJS_1) $(OBJS_2)

fclean: clean
		@rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean