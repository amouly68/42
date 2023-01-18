/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <amouly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:56:03 by amouly            #+#    #+#             */
/*   Updated: 2023/01/18 18:11:36 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int len_line(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\n')
        i++;
    return (i);
}

int len_list(t_map *list)
{
    int i;

    i = 0;
    while(list)
    {
        i++;
        list = list->next;   
    }
    return (i);
}

int	ft_addnode_back(t_map **list, t_map *new)
{
	t_map	*temp;

	if (list == NULL && new == NULL)
		return (0);
	if ((*list) == NULL)
	{
		(*list) = new;
		new->next = NULL;
	}
	else
	{
		temp = (*list);
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
	return (1);
}

int fill_list_map(t_map **list, int fd)
{
	t_map	*new;
    char    *line;
    int     len;
    
    line =  get_next_line(fd);
    len = len_line(line);
    while(line)
	{
        if (len != len_line(line))
            return (0);
        new = malloc(sizeof(t_map));
	    if (!new)
		    return (0);
	    new->line = line;
        new->next = NULL;
        line =  get_next_line(fd);
        if (!(ft_addnode_back(list, new)))
		    return (0);
    }
    return(len);
}

char *list_into_tab(t_map *map, int largeur)
{
    char    *tab;
    
    tab = malloc(sizeof(char) * (largeur + 1));
    if (tab == NULL)
        return (NULL);
    tab = map->line;
    tab[largeur] = '\0';
    return (tab);
}


char    **fill_tab_map(int fd)
{
    t_map *map;
    int largeur;
    int hauteur;
    int i;
    char **tab;

    i = 0;
    map = NULL;
    
    largeur = fill_list_map(&map, fd);
    if (largeur == 0)
    {
        free_list(&map);
        return(NULL);
    }
    hauteur = len_list(map);
    tab = malloc (sizeof(char *) * (hauteur + 1));
    if (tab == NULL)
        return (NULL) ;
    while(i < hauteur)
    {
        tab[i] = list_into_tab(map, largeur);
        if (tab[i] == NULL)
            return (NULL);
        map = map->next;
        i++; 
    }
    tab[i] = 0; 
    free_list(&map); 
    return (tab);  
}

int main ()
{
    int fd;
   //t_map *map;
    char **tab;
    
    fd = open("sources/test.ber", O_RDONLY);
    tab = fill_tab_map(fd);
    if (tab == NULL)
        free_tab(tab);
    print_tab(tab);
    free_tab(tab);
   
    
}