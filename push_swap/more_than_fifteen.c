/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_than_fifteen.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 18:09:06 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	fifteen_to_hundred(t_ps_list **list_a, t_ps_list **list_b, int argc)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		inf_borne_to_top(list_a, decile_2(*list_a));
		pb(list_b, list_a);
		i++;
	}
	while (*list_b)
	{
		max_to_top_b(list_b);
		pa(list_a, list_b);
	}
	return (0);
}

int	more_than_fifteen(t_ps_list **list_a, t_ps_list **list_b, int argc)
{
	int	i;

	i = 0;
	while (i < (argc - 1))
	{
		inf_borne_to_top(list_a, decile_1(*list_a));
		pb(list_b, list_a);
		i++;
	}
	while (*list_b)
	{
		max_to_top_b(list_b);
		pa(list_a, list_b);
	}
	return (0);
}
