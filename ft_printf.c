/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:01 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/29 16:49:40 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printffunc.h"

int	ft_flag_catch(va_list arr, const char *input)
{
    if (*input == 'c')
		return (ft_is_char(va_arg(arr, int))); //va_ veri tipi nasıl tanımlı veri tiğine dönüşüyor?
	else if (*input == 's')
		return (ft_is_string(va_arg(arr, char *)));
	else if (*input == 'x' || *input == 'X')
		return (ft_is_hex(va_arg(arr, unsigned int), *input)); //?
	else if (*input == 'p')
		return (ft_is_address(va_arg(arr, unsigned long)));
	else if (*input == 'd' || *input == 'i')
		return (ft_is_int(va_arg(arr, int)));
	else if (*input == 'u')
		return (ft_is_unsigned(va_arg(arr, unsigned int)));
	else if (*input == '%')
		return (ft_is_char(va_arg(arr, int)));
	else
		return ;
}

int	ft_printf(const char *input, ...)
{
	int	i;
    int	relen;
	va_list arr;
	
	va_start(arr, input);
	relen = 0;
	i = 0;
	while (input[i] != '\0')
	{
		if (input[i++] == '%')
			relen = ft_flag_catch(arr, input[i]);
		else
			relen = write(1, &(input[i]), 1);
		i++;
	}
	va_end(arr);
	return (relen);
}