NAME = libftprintf.a
LIBFT = libft
FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
		ft_printffunc.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
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