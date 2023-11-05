/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ulyildiz <ulyildiz@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 19:32:26 by ulyildiz          #+#    #+#             */
/*   Updated: 2023/11/04 19:34:35 by ulyildiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

static char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = 0;
	s2 = (char *)malloc(ft_strlen(s1) + 1);
	if (s2 == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

static int	ft_order(int n)
{
	int		i;
	float	j;

	j = (float)n;
	i = 0;
	if (n == 0)
		return (1);
	while (j >= 1 || j <= -1)
	{
		j /= 10;
		i++;
		if (j > -1 && j < 0)
			i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*array;
	int		j;

	j = ft_order(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	array = (char *)malloc(j + 1);
	if (array == NULL)
		return (NULL);
	array[j] = '\0';
	if (n < 0)
	{
		array[0] = '-';
		n *= -1;
	}
	if (n == 0)
		array[0] = '0';
	while (n > 0)
	{
		array[--j] = (n % 10) + '0';
		n /= 10;
	}
	return (array);
}