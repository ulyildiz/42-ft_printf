/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supfunc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 17:39:22 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/10/27 17:39:22 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_int(int a)
{
	char *output;

	output = ft_itoa(a);

}

int ft_is_string(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (1, &(s[i++]), 1);
}
int	ft_is_hex()
{

}

int	ft_is_unsigned()
{
	
}