NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printffunc.c

OBJ = (SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) *.o

.c.o:
	cc	$(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean