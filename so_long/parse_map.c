/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:56:03 by amouly            #+#    #+#             */
/*   Updated: 2023/01/14 13:03:57 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill_tab_map(int fd, char **tab)
{
    int i;
    char *temp;
    
    i = 0;
    while (get_next_line(fd) != NULL)
    {
        tab[i] = malloc   
    }
    
}