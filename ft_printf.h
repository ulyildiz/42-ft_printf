/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:12:42 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/11/04 16:31:41 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *input, ...);
int	ft_is_string(char *s);
int	ft_is_int(int i);
int	ft_is_unsigned(unsigned int un);
int	ft_is_hex(unsigned int hex, int to);
int	ft_is_address(unsigned long ul);

#endif