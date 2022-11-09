/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:39:19 by amouly            #+#    #+#             */
/*   Updated: 2022/11/09 17:09:39 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ret;
	t_list	*first;

	first = NULL;
	if (lst != NULL && (*f) != NULL && (*del) != NULL)
	{
		while (lst)
		{
			ret = ft_lstnew((*f)(lst->content));
			if (!ret)
				ft_lstclear(&first, (*del));
			ft_lstadd_back(&first, ret);
			lst = lst->next;
		}
	}
	return (first);
}
