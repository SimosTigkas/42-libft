/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 17:39:32 by stigkas           #+#    #+#             */
/*   Updated: 2023/10/31 18:20:23 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*s1;
	unsigned int	i;
	size_t			s_len;
	size_t			s1_len;

	s_len = ft_strlen(s);
	i = 0;

	if (s == NULL || start >= s_len || start < 0 || len <= 0)
		return (NULL);
	if (s_len - start > len)
		s1_len = len;
	else
		s1_len = s_len - start;
	s1 = (char *)(malloc(s1_len + 1));
	if (s1 == NULL)
		return (NULL);
	while (s[i] != '\0' && i < s1_len)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	main(void)
{
	const char		src[] = "Hello";
	char			*sbstr = ft_substr(src , 0, 3);

	if (sbstr != NULL)
	{
		printf("Substring: %s\n", sbstr);
		free(sbstr);
	}
	else
		printf("Invalid start or length provided.\n");
	return (0);
}
