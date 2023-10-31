#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "../42libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_is_int(int i);
int	ft_is_string(char *s);
int	ft_is_unsigned(unsigned int un);
int	ft_is_hex(unsigned int hex, int to);
int	ft_is_address(unsigned long ul);

#endif