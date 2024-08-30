NAME = push_swap

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -Werror
MFLAGS = -lXext -lX11 -lm -lbsd

# Directories

LIBFTDIR = ./ft_libft
FT_PRINTFDIR = ./ft_printf

# Source files
SRCS = main.c val.c freemem.c stack.c rotate.c swap.c rev_rotate.c push.c meccanicalkebab.c utilskebab.c partofmekeb.c
OBJS = $(SRCS:%.c=%.o)

# Executable name

all: $(NAME)

%.o: %.c | $(OBJS)
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

$(NAME): $(OBJS)
	make re -C $(LIBFTDIR)
	make re -C $(FT_PRINTFDIR)
	$(CC) $(OBJS) -L$(LIBFTDIR) -L$(FT_PRINTFDIR) -lftprintf -lft -o $(NAME)



clean:
	rm -rf $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
