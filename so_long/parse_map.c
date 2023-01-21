#include "so_long.h"

/*void first_line(t_so_long *sl, int fd)
{
    char    *line;
    
    
    line = get_next_line(fd);
    sl->map_width = len_line(line);
    line[sl->map_width] = '\0';
    if (!(all_one(line)))
        return ;
    sl->map_height = 1;
    sl->tab = malloc(sizeof (char *) * (sl->map_height + 1));
    if (sl->tab == NULL)
        return ;
    sl->tab[0] = malloc (sizeof (char) * (sl->map_width + 1)); 
    if (sl->tab[0] == NULL)
        return ;
    sl->tab[0] = line;
    sl->tab[1] = 0;  
   
}*/


void    init_sl(t_so_long *sl)
{
    sl->map = NULL;
    sl->tab = NULL;
    sl->map_height = 0;
    sl->map_width = 0;
    sl->collectible = 0;
    sl->exit = 0;
    sl->x_exit = 0;
	sl->y_exit = 0;
    sl->position = 0;
    sl->x_position = 0;
    sl->y_position = 0;
    
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

void fill_list_map(t_so_long *sl, int fd)
{
	t_map	*new;
    char    *line;
 
    line =  get_next_line(fd);
    sl->map_width = len_line(line);
    while(line)
	{
        sl->map_height++;
        new = malloc(sizeof(t_map));
	    if (!new)
		    return ;
	    new->line = line;
        new->next = NULL;
        line = get_next_line(fd);
        if(!(ft_addnode_back(&sl->map, new)))
		    return ;         
    }
}

void    list_to_tab(t_so_long *sl)
{
    int i;
    t_map *head;

    head = sl->map;
    i = 0;
    sl->tab = malloc(sizeof(char **) * (sl->map_height + 1));
    if (sl->tab == NULL)
        return;
    while(i < sl->map_height)
    {
        sl->tab[i] = sl->map->line;
        sl->tab[i][sl->map_width] = '\0';
        sl->map = sl->map->next;
        i++;
    }
    sl->tab[i] = 0;
    sl->map = head;
}

void parse_map(t_so_long *sl, int fd)
{
    fill_list_map(sl, fd);
    if (!(check_list(sl)))
    {
        free_list(&(sl->map));
        return;
    }
    
    list_to_tab(sl);
    if (!(check_tab(sl)))
    {
        free(sl->tab);
        sl->tab = NULL;
        free_list(&(sl->map));
        return;
    }
    
    print_tab(sl->tab);
    ft_printf("\n\nMap de %d x %d\n", sl->map_width, sl->map_height);
    ft_printf("Il y a %d collectibles\n", sl->collectible);
    ft_printf("La postion du joueur est %d,%d\n", sl->x_position, sl->y_position);
    ft_printf("La postion de la sortie est %d,%d\n", sl->x_exit, sl->y_exit);
    
    
    
    free(sl->tab);
    sl->tab = NULL;
    free_list(&(sl->map));

}