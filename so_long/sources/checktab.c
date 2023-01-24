/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:43:57 by amouly            #+#    #+#             */
/*   Updated: 2023/01/24 13:57:29 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int all_wall(char *line)
{
    int i;

    i = 0;
    while(line[i]) 
    {
        if (line[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

int line_wall(char *line)
{
    int end;

    end = ft_strlen(line) - 1;
    if (line[0] != '1')
            return (0);
    if (line[end] != '1')
            return (0);
    return (1);
}

int	ft_addnode_c_back(t_point **list, t_point *new)
{
	t_point	*temp;

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



void fill_list_collectible(t_so_long *sl, int i, int j)
{
	t_point	*new;
    
    new = malloc(sizeof(t_point));
	if (!new)
		return ;
	new->x_point = j;
    new->y_point = i;
    new->next = NULL;
    if(!(ft_addnode_c_back(&sl->collect_list, new)))
		    return ;         
}

void find_coordonates(t_so_long *sl)
{
    int i;
    int j;

    i = 1;
    while(sl->tab[i])
    {
        j = 1;
        while(sl->tab[i][j])
        {
             if (sl->tab[i][j] == 'P')
                {
                    sl->x_player = j;
                    sl->y_player = i;
                }
            else if (sl->tab[i][j] == 'E')
                {
                    sl->x_player = j;
                    sl->y_player = i;
                }
            else if (sl->tab[i][j] == 'C')
                    fill_list_collectible(sl, i, j);
            j++;
        }
        i++;
    }
}

int check_tab(t_so_long *sl)
{
    int i;

    i = 1;
    if (!(all_wall(sl->tab[0])))
    {
        ft_printf("Error\nMap non entoure de murs\n");
        return (0);
    }
    if (!(all_wall(sl->tab[sl->map_height - 1])))
    {
        ft_printf("Error\nMap non entoure de murs\n");
        return (0);
    }   
    while (i < (sl->map_height - 1))
    {
        if (!(line_wall(sl->tab[i])))
         {
            ft_printf("Error\nMap non entoure de murs\n");
            return (0);
        }  
        i++;
    }
    find_coordonates(sl);
    
    flood_fill(sl);
    return (1);
}