/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 14:03:42 by amouly            #+#    #+#             */
/*   Updated: 2022/11/09 17:31:43 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del) (void *))
{
	t_list	*temp;

	while ((*lst) != NULL && (*del) != NULL && lst != NULL)
	{
		temp = (*lst)->next;
		(*del)((*lst)->content);
		free(*lst);
		(*lst) = temp;
	}
	lst = NULL;
}
