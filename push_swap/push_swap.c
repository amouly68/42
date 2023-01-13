/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 17:20:19 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_ps_list	*pile_a;
	t_ps_list	*pile_b;
	int			len;

	pile_a = NULL;
	pile_b = NULL;
	if (!(fill_list_verif(&pile_a, argc, argv)))
	{
		clean_pile(&pile_a);
		return (-1);
	}
	if (pile_triee(pile_a))
	{
		clean_pile(&pile_a);
		return (-1);
	}
	len = count_pile(pile_a);
	if (len < 4)
		less_than_four(&pile_a, len);
	if (len >= 4 && len < 16)
		four_to_fifteen(&pile_a, &pile_b, len + 1);
	if (len > 15)
		more_than_fifteen(&pile_a, &pile_b, len + 1);
	clean_pile(&pile_a);
	return (0);
}
