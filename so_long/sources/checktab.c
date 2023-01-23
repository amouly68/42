/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:43:57 by amouly            #+#    #+#             */
/*   Updated: 2023/01/23 13:39:28 by amouly           ###   ########.fr       */
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

void find_P(t_so_long *sl)
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
                    sl->x_player = i;
                    sl->y_player = j;
                }
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
    find_P(sl);
    flood_fill(sl);
    return (1);
}