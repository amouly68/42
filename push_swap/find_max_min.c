/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 12:43:41 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_ps_list	*find_max(t_ps_list *list)
{
	t_ps_list	*ret;

	ret = list;
	while (list)
	{
		if (list->nbr > ret->nbr)
			ret = list;
		list = list->next;
	}
	return (ret);
}

int	index_max(t_ps_list *list)
{
	int	index;
	int	max;

	index = 0;
	max = (find_max(list)->nbr);
	while (list)
	{
		if (list->nbr == max)
			break ;
		index++;
		list = list->next;
	}
	return (index);
}

t_ps_list	*find_min(t_ps_list *list)
{
	t_ps_list	*ret;

	ret = list;
	while (list)
	{
		if (list->nbr < ret->nbr)
			ret = list;
		list = list->next;
	}
	return (ret);
}

int	index_min(t_ps_list *list)
{
	int	index;
	int	min;

	index = 0;
	min = (find_min(list)->nbr);
	while (list)
	{
		if (list->nbr == min)
			break ;
		index++;
		list = list->next;
	}
	return (index);
}
