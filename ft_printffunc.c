/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:39:22 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/31 16:29:18 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_is_int(int i)
{
	char	*output;
	int		esc;

	output = ft_itoa(i);
	esc = ft_strlen(output);
	ft_putstr_fd(output, 1);
	free(output);
	return (esc);
}

int	ft_is_string(char *s)
{
	int	esc;

	esc = 0;
	while (s[esc] != '\0')
		write (1, &(s[esc++]), 1);
	return (esc);
}

int	ft_is_hex(unsigned int hex, int to)
{
	int	esc;

	esc = 0;
	if (hex >= 16)
		esc += ft_is_hex(hex / 16, to);
	if (to == 'x')
		write (1, &"0123456789abcdef"[hex % 16], 1);
	else if (to == 'X')
		write (1, &"0123456789ABCDEF"[hex % 16], 1);
	return (++esc);
}

int	ft_is_address(unsigned long ul)
{
	int	esc;

	esc = 0;
	if (ul >= 16)
	{
		if (ul / 16 < 16)
			esc += write (1, "0x", 2);
		esc += ft_is_address(ul / 16);
		write(1, &"0123456789abcdef"[ul % 16], 1);
		return (++esc);
	}
	write(1, &"0123456789abcdef"[ul % 16], 1);
	return (++esc);
}

int	ft_is_unsigned(unsigned int un)
{
	int	esc;

	esc = 0;
	if (un > 10)
	{
		esc += ft_is_unsigned(un / 10);
		write(1, &"0123456789"[un % 10], 1);
		return (++esc);
	}
	write(1, &"0123456789"[un % 10], 1);
	return (++esc);
}
