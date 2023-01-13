/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:46:18 by amouly            #+#    #+#             */
/*   Updated: 2023/01/13 17:59:13 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

int	ft_addnode_back(t_ps_list **list, t_ps_list *new)
{
	t_ps_list	*temp;

	if (list == NULL && new == NULL)
		return (0);
	if ((*list) == NULL)
	{
		(*list) = new;
		new->next = NULL;
	}
	else
	{
		temp = (*list);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

int	fill_list(t_ps_list **list, int nbr)
{
	t_ps_list	*new;

	new = malloc(sizeof(t_ps_list));
	if (!new)
		return (0);
	new->nbr = nbr;
	new->next = NULL;
	if (!(ft_addnode_back(list, new)))
		return (0);
	return (1);
}

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	fill_split(t_ps_list **list, int argc, char **argv)
{
	int		i;
	int		j;
	char	**split;

	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		j = 0;
		while (split[j])
		{
			if (!(check_error(split[j])))
				return (0);
			if (!(fill_list(list, ft_atoi(split[j]))))
				return (0);
			j++;
		}
		free_split(split);
		i++;
	}
	return (1);
}

int	fill_list_verif(t_ps_list **list, int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (!(fill_split(list, argc, argv)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (!(check_list(*list)))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	return (1);
}
