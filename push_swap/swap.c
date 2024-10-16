/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 17:10:37 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	swap(t_ps_list **list)
{
	t_ps_list	*first;
	t_ps_list	*second;
	t_ps_list	*third;

	if (!list || !(*list) || !((*list)->next))
		return ;
	first = (*list)->next;
	second = *list;
	third = ((*list)->next)->next;
	*list = first;
	first->next = second;
	second->next = third;
}

void	sa(t_ps_list **list)
{
	swap(list);
	ft_printf("sa\n");
}

void	sb(t_ps_list **list)
{
	swap(list);
	ft_printf("sb\n");
}

void	ss(t_ps_list **list_a, t_ps_list **list_b)
{
	swap(list_a);
	swap(list_b);
	ft_printf("ss\n");
}
