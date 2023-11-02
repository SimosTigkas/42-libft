/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 16:54:38 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/02 14:01:27 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*last;

	last = NULL;
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	while (*s)
	{
		if (*s == (char)c)
			last = (char *)s;
		s++;
	}
	return (last);
}
