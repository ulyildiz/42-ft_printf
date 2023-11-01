/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:12:42 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/11/01 08:38:17 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"

int	ft_printf(const char *input, ...);
int	ft_is_char(char c);
int	ft_is_string(char *s);
int	ft_is_unsigned(unsigned int un);
int	ft_is_hex(unsigned int hex, int to);
int	ft_is_address(unsigned long ul);

#endif