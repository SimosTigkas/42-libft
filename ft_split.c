/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:00:26 by stigkas           #+#    #+#             */
/*   Updated: 2023/10/31 15:51:49 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (i < dstsize && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	while (src[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	j;
	size_t	i;
	size_t	counter;
	char	**res;
	size_t	start;

	j = 0;
	i = 0;
	counter = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			counter++;
	}
	res = (char **)malloc((counter + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[j] = (char *)malloc(i - start + 1);
		if (!res[j])
			return (NULL);
		ft_strlcpy(res[j], s + start, i - start);
		res[j++][i - start] = '\0';
		if (s[i])
			i++;
	}
	res[j] = NULL;
	return (res);
}

void	freesplitresult(char **result)
{
	int	i;

	i = 0;
	if (result)
	{
		while (result[i])
		{
			free(result[i]);
			i++;
		}
		free(result);
	}
}

int	main(void)
{
	const char	*input = "Hello,World,How,Are,You";
	char		d = ',';
	int			i = 0;
	char		**result = ft_split(input, d);

	if (result)
	{
		while (result[i])
		{
			printf("Token %d: %s\n", i, result[i]);
			i++;
		}
		freesplitresult(result);
	}

    return (0);
}