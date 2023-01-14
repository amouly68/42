/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:56:03 by amouly            #+#    #+#             */
/*   Updated: 2023/01/14 15:01:14 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void print_tab(char **tab)
{
    int i;
    
    i = 0;
    while(tab[i])
        ft_printf("%s\n", tab[i++]);

}


int len_line(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\n')
        i++;
    return (i);
}


void fill_tab_map(int fd, char **tab)
{
    int i;
    char *temp;
    
    i = 0;
    temp = get_next_line(fd);
    while ( temp != NULL)
    {
        tab[i] = malloc(sizeof(char) * (len_line(temp) + 1));
        tab[len_line(temp)] = '\0';
        temp = get_next_line(fd);
        i++;
    }
    tab[i] = NULL;
    
}

int main ()
{
    int fd;

    fd = open("test.txt", O_RDONLY);
}