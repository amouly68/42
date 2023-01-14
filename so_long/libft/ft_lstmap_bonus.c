/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:39:19 by amouly            #+#    #+#             */
/*   Updated: 2022/11/16 12:34:47 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*new_proofed(void *content, void (*del)(void *))
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
	{	
		(del)(content);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*first;

	first = NULL;
	if (lst != NULL && (*f) != NULL && (*del) != NULL)
	{
		while (lst)
		{
			ret = new_proofed((*f)(lst->content), (del));
			if (ret == NULL)
				ft_lstclear(&first, (*del));
			ft_lstadd_back(&first, ret);
			lst = lst->next;
		}
	}
	return (first);
}
