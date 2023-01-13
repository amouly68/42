/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 12:44:24 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_ps_list	*ft_getprelast(t_ps_list *list)
{
	if (!list)
		return (list);
	while (list->next->next)
		list = list->next;
	return (list);
}

void	reverse(t_ps_list **list)
{
	t_ps_list	*first;
	t_ps_list	*second;
	t_ps_list	*last;

	if ((!(list)) || (!(*list)) || (!((*list)->next)))
		return ;
	first = ft_getlast(*(list));
	second = *list;
	last = ft_getprelast(*list);
	*list = first;
	first->next = second;
	last->next = NULL;
}

void	rra(t_ps_list **list)
{
	reverse(list);
	ft_printf("rra\n");
}

void	rrb(t_ps_list **list)
{
	reverse(list);
	ft_printf("rrb\n");
}

void	rrr(t_ps_list **list_a, t_ps_list **list_b)
{
	reverse(list_a);
	reverse(list_b);
	ft_printf("rrr\n");
}
