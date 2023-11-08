/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stigkas <stigkas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 09:40:59 by stigkas           #+#    #+#             */
/*   Updated: 2023/11/08 11:02:18 by stigkas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_lstnew((f)(lst->content));
	if (!res)
		return (NULL);
	while (lst)
	{
		new = ft_lstnew((f)(lst->content));
		if (!(new))
		{
			ft_lstclear(&(res), del);
			return (NULL);
		}
		ft_lstadd_back(&res, new);
		lst = lst->next;
	}
	return (res);
}
