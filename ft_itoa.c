/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:33:59 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/02 11:04:19 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fillthestring(int i, char *str)
{
	char	temp;
	int		start;
	int		end;

	start = 0;
	end = i - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
	return (str);
}

int	num_len(int n)
{
	int	c;

	c = 0;
	while (n > 0)
	{
		n /= 10;
		c++;
	}
	return (c);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		cl;
	int		start;
	int		end;

	i = 0;
	cl = num_len(n);
	str = (char *)malloc((cl + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
	{
		str[i++] = '-';
		n = -n;
	}
	while (n != 0)
	{
		str[i++] = '0' + (n % 10);
		n /= 10;
	}
	str[i] = '\0';
	return (ft_fillthestring(i, str));
}
