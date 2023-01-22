/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:39:24 by amouly            #+#    #+#             */
/*   Updated: 2023/01/18 16:49:23 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_list(t_map *list)
{
    int i;

    i = 0;
    while(list)
    {
        ft_printf("noeud %d : %s\n",i, list->line);
        i++;
        list = list->next;
    }
}

void print_tab(char **tab)
{
    int i;
    
    i = 0;
    while(tab[i])
        ft_printf("%s\n", tab[i++]);
    ft_printf("%s", tab[i]);
}