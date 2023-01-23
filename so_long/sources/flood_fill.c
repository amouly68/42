/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:13:49 by amouly            #+#    #+#             */
/*   Updated: 2023/01/23 13:39:56 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int fill(t_so_long  *sl, int i, int j)
{
   //char **tab = sl->tab;
   ft_printf("i = %d, j = %d, largeur = %d, haueteur = %d\n", i, j, sl->map_width, sl->map_height);
   ft_printf("UO");
   ft_printf("%c\n", sl->tab[i][j]);
   if (i <= 0 || j <= 0 || i >= (sl->map_width - 1) || j >= (sl->map_height - 1)
        || sl->tab[i][j] == '1' )
        return (0);
    ft_printf("UO");
    if (sl->tab[i][j] == 'E')
        return (1);
    if (!(fill (sl, i + 1, j)))
        return (0);
    if (!(fill (sl, i - 1, j)))
        return (0);
    if (!(fill (sl, i, j + 1)))
        return (0);
    if (!(fill (sl, i, j - 1)))
        return (0);
    return (1);
    
}


void flood_fill(t_so_long *sl)
{
    int x = sl->x_player;
    int y = sl->y_player;
    print_tab(sl->tab);
    ft_printf("position du joueur ----> x : %d | y  : %d \n", x, y);
    ft_printf("C : %c", sl->tab[x][y]);
   // if (fill(sl, sl->x_player, sl->y_player))
       // ft_printf("Le joueur peut sortir");
}