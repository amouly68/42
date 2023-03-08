/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:03:31 by event             #+#    #+#             */
/*   Updated: 2023/03/08 15:39:16 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void    parse_input(char *input)
{
    char    **tab;
    int     i;
    int     nb_of_pipes;
    t_int   *list_of_index;
    
    i = 0;
    list_of_index = NULL;
    nb_of_pipes = 0;
    tab = ft_split_ms(format_line(input));
    while(tab[i])
    {
        if (tab[i][0] == '|' && tab[i][1] == '\0')
        {
            nb_of_pipes++;
            fill_list_int(i, &list_of_index);   
        }   
        i++;
    }
    printf("il y a %d pipes aux index suivants :\n", nb_of_pipes);
    print_list_int_from_head(list_of_index);
    printf("---------------");
    print_list_int_from_bottom(list_of_index);
    
}