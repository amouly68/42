/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checktab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 12:43:57 by amouly            #+#    #+#             */
/*   Updated: 2023/01/23 09:56:17 by amouly           ###   ########.fr       */
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

/*void find_E_P(t_so_long *sl)
{
    int i;
    int j;

    i = 1;
    while(sl->tab[i])
    {
        j = 1;
        while(sl->tab[i][j])
        {
            if (sl->tab[i][j] == 'E')
                {
                    sl->x_exit = j;
                    sl->y_exit = i;
                }
             if (sl->tab[i][j] == 'P')
                {
                    sl->x_position = j;
                    sl->y_position = i;
                }
            j++;
        }
        i++;
    }
}*/

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
    //find_E_P(sl);
    return (1);
}