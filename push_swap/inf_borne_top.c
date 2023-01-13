/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_borne_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 12:45:08 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sup_borne_to_top(t_ps_list **list, int borne)
{
	int	index_rotate;
	int	index_reverse;
	int	nbre;

	nbre = count_pile(*list);
	index_rotate = index_rot_superieur(*list, borne);
	index_reverse = index_rev_superieur(*list, borne);
	if (index_rotate < (nbre - index_reverse))
	{
		while (index_rotate > 0)
		{
			ra(list);
			index_rotate--;
		}
	}
	else
	{
		while (index_reverse < nbre)
		{
			rra(list);
			index_reverse++;
		}
	}
}

void	inf_borne_to_top(t_ps_list **list, int borne)
{
	int index_rotate;
	int index_reverse;
	int nbr;

	nbr = count_pile(*list);
	index_rotate = index_rot_inferieur(*list, borne);
	index_reverse = index_rev_inferieur(*list, borne);
	if (index_rotate < (nbr - index_reverse))
	{
		while (index_rotate > 0)
		{
			ra(list);
			index_rotate--;
		}
	}
	else
	{
		while (index_reverse < nbr)
		{
			rra(list);
			index_reverse++;
		}
	}
}