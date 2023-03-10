/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:03:31 by event             #+#    #+#             */
/*   Updated: 2023/03/10 13:02:37 by amouly           ###   ########.fr       */
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


void handle_chevrons(char **tab, int index)
{
    if (tab[index][0] == '<')
    {
        if (tab[index][1] == '<')
            printf("Il y a un delimiteur qui est : %s\n", tab[index + 1]);
        else
            printf("Input redirected from file : %s\n", tab[index + 1]);
    }
    else
    {
        if (tab[index][1] == '>')
            printf("Output redirected and APPENDED to file : %s\n", tab[index + 1]);
        else
            printf("Output redirected to file : %s\n", tab[index + 1]);
    }
}


void find_command_until_pipe(char **tab, int *i, int *cmd)
{
    //int i;
    //int cmd;
    int arg;

    //i = 0;
    //cmd = 0;
    arg = 0;
    if (tab[*i][0] == '<' || tab[*i][0] == '>')
    {
        handle_chevrons(tab, *i);
        (*i)++;
    }
    else 
    {
        if (*cmd == 0)
        {
            printf("la commande est : %s\n", tab[*i]);
            *cmd = 1;
        }
        else 
            printf("arg ou option num %d : %s\n", ++arg, tab[*i]); 
    }
   // i++;
}

/*void    parse_between_pipes(t_number *list_of_index, char **tab)
{
    t_number   *temp;
    
    temp = list_of_index;
    while(temp)
    {
        find_command_until_pipe(tab, temp->nbr);
        temp = temp->next;
    }
}*/

/*void    parse_input(char *input)
{
    char    **tab;
    int     nb_of_pipes = 0;
    //int     i = 0;
    t_number   *list_of_index;
    
    list_of_index = NULL;
    tab = ft_split_ms(format_line(input));
    print_input_after_formating(input);
    nb_of_pipes = (count_nb_of_pipes(tab, &list_of_index));
    printf("il y a %d pipes aux index suivants :\n", nb_of_pipes);
    print_list_int_from_head(list_of_index);
    printf("---------------\n");
    print_list_int_from_bottom(list_of_index);
    parse_between_pipes(list_of_index, tab);
    
}*/

void    parse_input(char *input)
{
    char    **tab;
    int     i;
    int     pipe;
    int     cmd;
    
    i = 0;
    pipe = 0;
    
    tab = ft_split_ms(format_line(input));
     while(tab[i])
    {
        printf("tab[%d] = %s\n",i,tab[i]);
        i++;  
    }
   // print_input_after_formating(input);
    i = 0;
    while(tab[i])
    {
        cmd = 0;
        while(tab[i] && (tab[i][0] != '|' || tab[i][1] != '\0'))
        {
            find_command_until_pipe(tab, &i, &cmd);
            i++;
        }
        if (tab[i] && (tab[i][0] == '|' && tab[i][1] == '\0'))
        {    
            printf("Pipe num %d\n", ++pipe);
            i++;
        }
    }
}