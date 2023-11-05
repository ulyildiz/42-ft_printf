NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printffunc.c \
		ft_printf_util.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) *.o

all: $(NAME)

.c.o:
	cc	$(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: re all clean fclean