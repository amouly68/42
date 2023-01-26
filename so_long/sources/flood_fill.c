/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:13:49 by amouly            #+#    #+#             */
/*   Updated: 2023/01/26 09:29:11 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void copy_tab(t_so_long *sl, char **tab_copy)
{
    int i;
    int j;

    i = 0;
    while (i < sl->map_height)
    {
        tab_copy[i] = malloc(sizeof(char) * (sl->map_width + 1));
        if (tab_copy == NULL)
            return ;
        j = 0;
        while (sl->tab[i][j])
        {
            tab_copy[i][j] = sl->tab[i][j];
            j++;
        }
        i++;
    } 
    tab_copy[i] = 0;
}

int check_copy_tab(t_so_long *sl, char **tab_copy)
{
    t_point *head;

    
    //ft_printf("y->Exit : %d y->Exit : %d\n", sl->y_exit, sl->x_exit );
    if (tab_copy[sl->y_exit][sl->x_exit] != '1')
        return (0);
   // ft_printf("Exit : %c", tab_copy[sl->y_exit][sl->x_exit] );
    head = sl->collect_list;
    while (sl->collect_list)
    {
        if (tab_copy[sl->collect_list->y_point][sl->collect_list->x_point] != '1' )
            return (0);
        sl->collect_list = sl->collect_list->next;
    } 
    sl->collect_list = head;
    return (1);
}

void fill(char **tab, t_so_long *sl, int x, int y)
{
   if (x <= 0 || y <= 0 || x >= (sl->map_width ) || y >= (sl->map_height )
        || tab[y][x] == '1'  || tab[y][x] == 'M' )
        return ;
    tab[y][x] = '1';
    fill (tab, sl, x + 1, y);
    fill (tab, sl, x - 1, y);
    fill (tab, sl, x, y + 1);
    fill (tab, sl, x, y - 1);
}

int flood_fill(t_so_long *sl)
{
    char **tab_copy;

    tab_copy = malloc(sizeof(char *) * (sl->map_height + 1));
    if (tab_copy == NULL)
        return (0);
    copy_tab(sl, tab_copy);
    //print_tab(tab_copy);
    //ft_printf ("x joueur : %d et y joueur : %d\n", sl->x_player, sl->y_player);
    fill(tab_copy, sl, sl->x_player, sl->y_player);
    //ft_printf("tab_copy apres fill: \n");
    //print_tab(tab_copy);
    if (!(check_copy_tab(sl, tab_copy)))
        return (0);
   // print_tab(tab_copy);
    free_tab(tab_copy);
    return (1);
}