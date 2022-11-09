/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 09:39:59 by amouly            #+#    #+#             */
/*   Updated: 2022/11/09 16:51:03 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)

{
	t_list	*temp;

	if (new != NULL && lst != NULL)
	{
		if ((*lst) == NULL)
		{
			(*lst) = new;
			new->next = NULL;
		}
		else
		{
			temp = (*lst);
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new;
		}
	}
}
