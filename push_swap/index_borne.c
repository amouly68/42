/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_borne.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 12:43:45 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	index_rot_superieur(t_ps_list *list, int borne)
{
	int	index_rotate;

	index_rotate = 0;
	while (list)
	{
		if (list->nbr > borne)
			break ;
		index_rotate++;
		list = list->next;
	}
	return (index_rotate);
}

int	index_rev_superieur(t_ps_list *list, int borne)
{
	int	index_rev;
	int	i;

	index_rev = 0;
	i = 0;
	while (list)
	{
		if (list->nbr > borne)
			index_rev = i;
		i++;
		list = list->next;
	}
	return (index_rev);
}

int	index_rot_inferieur(t_ps_list *list, int borne)
{
	int	index_rotate;

	index_rotate = 0;
	while (list)
	{
		if (list->nbr < borne)
			break ;
		index_rotate++;
		list = list->next;
	}
	return (index_rotate);
}

int	index_rev_inferieur(t_ps_list *list, int borne)
{
	int index_rev;
	int i;

	index_rev = 0;
	i = 0;
	while (list)
	{
		if (list->nbr < borne)
			index_rev = i;
		i++;
		list = list->next;
	}
	return (index_rev);
}