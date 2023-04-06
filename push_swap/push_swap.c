/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/03/06 09:56:17 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_by_numbers(int len, t_ps_list **list_a, t_ps_list **list_b)
{
	if (len < 4)
		less_than_four(list_a, len);
	if (len >= 4 && len < 16)
		four_to_fifteen(list_a, list_b, len + 1);
	if (len >= 15 && len < 101)
		fifteen_to_hundred(list_a, list_b, len + 1);
	if (len > 100)
		more_than_fifteen(list_a, list_b, len + 1);
}
void print_list_test(t_ps_list *pile)
{
	t_ps_list *head = pile;

	while(head)
	{
		ft_printf("%d\n", head->nbr);
		head = head->next;
	}
	
}

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
	sort_by_numbers(len, &pile_a, &pile_b);
	print_list_test(pile_a);
	clean_pile(&pile_a);
	return (0);
}
