/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:42 by amouly            #+#    #+#             */
/*   Updated: 2022/11/08 17:14:40 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;
	if (lst != NULL ||  (*lst) != NULL)
	{
	i	temp = (*lst);
		while (temp != NULL)
		{
			temp = (*lst)->next;
			(*del) ((*lst)->content);
			free(*lst);
		}
		if (temp == NULL)
		{
			(*del) ((*lst)->content);
			free(*lst);
		}
	}
	lst = NULL;
}
