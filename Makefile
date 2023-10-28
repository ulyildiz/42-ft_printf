NAME = libftprintf.a
CC = CC
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		

OBJ = (SRC:.c=.o)

$(NAME): $(OBJ)
	a rc $(NAME) *.o

all: $(NAME)

.c.o:
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean