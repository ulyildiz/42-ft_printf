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
	rm -rf libft/*.o

fclean: clean
	rm -rf $(NAME)
	rm -rf libft/libft.a

re: fclean all

.PHONY: re all clean fclean