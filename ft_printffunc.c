/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printffunc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:39:22 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/11/04 19:16:50 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft/libft.h"

int	ft_is_int(int i)
{
	char	*output;
	int		esc;
	int		check;

	check = 0;
	output = ft_itoa(i);
	if (output == NULL)
		return (-1);
	esc = ft_strlen(output);
	check = write(1, output, esc);
	if (check == -1)
	{
		free(output);
		return (-1);
	}
	free(output);
	return (esc);
}

int	ft_is_string(char *s)
{
	int	esc;
	int	check;

	check = 0;
	esc = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	while (s[esc] != '\0')
	{
		check = write (1, &(s[esc++]), 1);
		if (check == -1)
			return (-1);
	}
	return (esc);
}

int	ft_is_hex(unsigned int hex, int to)
{
	int	esc;
	int	check;

	check = 0;
	esc = 0;
	if (hex >= 16)
		esc += ft_is_hex(hex / 16, to);
	if (esc == -1)
		return (-1);
	if (to == 'x')
		check = write (1, &"0123456789abcdef"[hex % 16], 1);
	else if (to == 'X')
		check = write (1, &"0123456789ABCDEF"[hex % 16], 1);
	if (check == -1)
		return (-1);
	return (++esc);
}

int	ft_is_address(unsigned long ul)
{
	int	esc;
	int	check;

	check = 0;
	esc = 0;
	if (ul < 16)
		esc += write (1, "0x", 2);
	if (esc == -1)
		return (-1);
	if (ul >= 16)
	{
		check = ft_is_address(ul / 16);
		if (check == -1)
			return (-1);
		esc += check;
		check = write(1, &"0123456789abcdef"[ul % 16], 1);
		if (check == -1)
			return (-1);
		return (++esc);
	}
	check = write(1, &"0123456789abcdef"[ul % 16], 1);
	if (check == -1)
		return (-1);
	return (++esc);
}

int	ft_is_unsigned(unsigned int un)
{
	int	esc;
	int	check;

	check = 0;
	esc = 0;
	if (un >= 10)
	{
		check = ft_is_unsigned(un / 10);
		if (check == -1)
			return (-1);
		esc += check;
		check = write(1, &"0123456789"[un % 10], 1);
		if (check == -1)
			return (-1);
		return (++esc);
	}
	check = write(1, &"0123456789"[un % 10], 1);
	if (check == -1)
		return (-1);
	return (++esc);
}
