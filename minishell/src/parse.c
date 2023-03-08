/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: event <event@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:03:31 by event             #+#    #+#             */
/*   Updated: 2023/03/08 16:28:20 by event            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int count_nb_of_pipes(char **tab, t_number **list)
{
    int i;
    int nb_of_pipes;
    t_number **temp;
    
    temp = list;
    i = 0;
    nb_of_pipes = 0;
    while(tab[i])
    {
        if (tab[i][0] == '|' && tab[i][1] == '\0')
        {
            nb_of_pipes++;
            fill_list_int(i, temp);   
        }   
        i++;
    }
    return (nb_of_pipes);
}


/*void handle_chevrons(char **tab, int index)
{
    if (tab[i][0] == '<')
    {
        if 
    }
}


void find_command_until_pipe(char **tab, int index_next_pipe)
{
    int i;
    int cmd;
    int arg;

    i = 0;
    cmd = 0;
    arg = 0;
    while (i < index_next_pipe)
    {
        if (tab[i][0] == '<' || tab[i][0] == '>')
        {
            handle_chevrons(tab, i);
            i++;
        }
        else 
        {
            if (cmd = 0)
            {
                printf("la commande est : %s\n", tab[i]);
                cmd = 1;
            }
            else 
                printf("arg ou option num %d : %s\n", ++arg, tab[i]); 
        }
        i++;
    }
}
*/


void    parse_input(char *input)
{
    char    **tab;
    int     nb_of_pipes = 0;
    int     i = 0;
    t_number   *list_of_index;
    
    list_of_index = NULL;
    tab = ft_split_ms(format_line(input));
    //print_input_after_formating(input);
    while(tab[i])
    {
        if (tab[i][0] == '|' && tab[i][1] == '\0')
        {
            nb_of_pipes++;
            fill_list_int(i, &list_of_index);   
        }   
        i++;
    }
   // nb_of_pipes = (count_nb_of_pipes(tab, &list_of_index));
    printf("il y a %d pipes aux index suivants :\n", nb_of_pipes);
    print_list_int_from_head(list_of_index);
    printf("---------------\n");
    print_list_int_from_bottom(list_of_index);
    
}