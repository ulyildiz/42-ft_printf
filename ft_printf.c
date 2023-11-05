/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:01 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/11/04 19:27:26 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_char(char c)
{
	return (write(1, &c, 1));
}

static int	ft_flag_catch(va_list arr, const char *input)
{
	if (*input == 'c')
		return (ft_is_char(va_arg(arr, int)));
	else if (*input == 's')
		return (ft_is_string(va_arg(arr, char *)));
	else if (*input == 'x' || *input == 'X')
		return (ft_is_hex(va_arg(arr, unsigned int), *input));
	else if (*input == 'p')
		return (ft_is_address(va_arg(arr, unsigned long)));
	else if (*input == 'd' || *input == 'i')
		return (ft_is_int(va_arg(arr, int)));
	else if (*input == 'u')
		return (ft_is_unsigned(va_arg(arr, unsigned int)));
	else if (*input == '%')
		return (write(1, "%%", 1));
	else
		return (-1);
}

int	ft_printf(const char *input, ...)
{
	int		f;
	int		i;
	int		relen;
	va_list	arr;

	va_start(arr, input);
	relen = 0;
	f = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i] == '%')
			f = ft_flag_catch(arr, &(input[++i]));
		else
			f = write(1, (input + i), 1);
		if (f == -1)
			return (-1);
		relen += f;
		i++;
	}
	va_end(arr);
	return (relen);
}
