/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:00:26 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/08 13:51:48 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		count_the_strings(char const *s, char c);
static char			**finall(char **res, const char *s, char c, size_t counter);
static size_t		find_nextlength(size_t b, const char *s, char c);
static char			*n_s(char *res, const char *s, size_t b, size_t len );

static size_t	count_the_strings(const char *s, char c)
{
	size_t	count;
	size_t	i;
	size_t	len;

	i = 0;
	count = 0;
	len = ft_strlen(s);
	if (len == 0)
		return (count);
	while (i < len)
	{
		while (s[i] == c && i < len)
			i++;
		if (count == 0 && i == len)
			return (0);
		if (count != 0 && i == len)
			count--;
		while (s[i] != c && i < len)
			i++;
		count++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	size_t	cn;
	char	**res;

	if (!s)
		return (NULL);
	cn = count_the_strings(s, c);
	res = (char **)malloc((cn + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	res = finall(res, s, c, cn);
	if (!res)
		return (NULL);
	return (res);
}

static char	**finall(char **res, const char *s, char c, size_t counter)
{
	size_t	b;
	size_t	j;
	size_t	l;

	b = 0;
	l = 0;
	while (l < counter)
	{
		j = find_nextlength(b, s, c);
		res[l] = (char *)malloc((j + 1) * sizeof(char *));
		if (res[l] == NULL)
		{
			while (l > 0)
			{
				free(res[l - 1]);
				l--;
			}
			free(res);
			return (NULL);
		}
		res[l] = n_s(res[l], s, b, j);
		l++;
	}
	res[l] = NULL;
	return (res);
}

static size_t	find_nextlength(size_t b, const char *s, char c)
{
	size_t	fnl;
	size_t	s_length;

	s_length = ft_strlen(s);
	fnl = 0;
	while (s[b] == c && b < s_length)
		b++;
	if (s[b] == '\0')
		return (0);
	while (s[b + fnl] != c && s[b + fnl] != '\0')
		fnl++;
	if (s[(b) + fnl - 1] == '\0')
		fnl--;
	return (fnl);
}

static char	*n_s(char *res, const char *s, size_t b, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		res[i] = s[b + i];
		i++;
	}
	res[i] = '\0';
	b = b + i;
	return (res);
}
