/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 17:53:50 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

void	sort_tab(int *tab, int length)
{
	int	temp;
	int	i;

	i = 0;
	while (i < length - 1)
	{
		if (tab[i + 1] < tab[i])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
}

int	decile_1(t_ps_list *list)
{
	int	nbr;
	int	i;
	int	*tab;
	int	decile;

	i = 0;
	nbr = count_pile(list);
	tab = malloc(sizeof(int) * nbr);
	if (tab == NULL)
		return (-1);
	while (list)
	{
		tab[i] = list->nbr;
		list = list->next;
		i++;
	}
	sort_tab(tab, nbr);
	decile = tab[nbr / 10];
	free(tab);
	return (decile);
}

int	decile_2(t_ps_list *list)
{
	int	nbr;
	int	i;
	int	*tab;
	int	decile;

	i = 0;
	nbr = count_pile(list);
	tab = malloc(sizeof(int) * nbr);
	if (tab == NULL)
		return (-1);
	while (list)
	{
		tab[i] = list->nbr;
		list = list->next;
		i++;
	}
	sort_tab(tab, nbr);
	decile = tab[nbr / 5];
	free(tab);
	return (decile);
}

int	pile_triee(t_ps_list *list)
{
	while (list->next)
	{
		if (list->next->nbr < list->nbr)
			return (0);
		list = list->next;
	}
	return (1);
}
