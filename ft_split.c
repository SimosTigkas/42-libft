/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:00:26 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/06 13:19:25 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_the_strings(const char *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	cn;
	char	**res;
	size_t	start;

	cn = count_the_strings(s, c);
	res = (char **)malloc((cn + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = -1;
	cn = 0;
	start = i;
	while (s[i++] != '\0')
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[cn] = (char *)malloc(i - start + 1);
		if (!res[cn])
			return (NULL);
		ft_strlcpy(res[cn], s + start, i - start);
		cn++;
	}
	res[cn] = NULL;
	return (res);
}
