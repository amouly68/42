/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_pile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 17:14:22 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	clean_pile(t_ps_list **list_a)
{
	t_ps_list	*next;

	next = NULL;
	if (list_a == NULL)
		return ;
	while (*list_a)
	{
		next = (*list_a)->next;
		free(*list_a);
		*list_a = next;
	}
}
