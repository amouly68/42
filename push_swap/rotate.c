/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 12:44:28 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_ps_list	*ft_getlast(t_ps_list *list)
{
	if (!list)
		return (list);
	while (list->next)
		list = list->next;
	return (list);
}

void	rotate(t_ps_list **list)
{
	t_ps_list	*first;
	t_ps_list	*prelast;
	t_ps_list	*last;

	if ((!(list)) || (!(*list)) || (!((*list)->next)))
		return ;
	first = (*list)->next;
	prelast = ft_getlast(*list);
	last = *list;
	*list = first;
	prelast->next = last;
	last->next = NULL;
}

void	ra(t_ps_list **list)
{
	rotate(list);
	ft_printf("ra\n");
}

void	rb(t_ps_list **list)
{
	rotate(list);
	ft_printf("rb\n");
}

void	rr(t_ps_list **list_a, t_ps_list **list_b)
{
	rotate(list_a);
	rotate(list_b);
	ft_printf("rr\n");
}
