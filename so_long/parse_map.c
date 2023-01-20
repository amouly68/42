#include "so_long.h"

void first_line(t_so_long *sl, int fd)
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
   
}


void    init_sl(t_so_long *sl)
{
    sl->map = NULL;
    sl->map_height = 0;
    sl->map_width = 0;
    sl->tab = NULL;
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
        line =  get_next_line(fd);
        if(!(ft_addnode_back(&sl->map, new)))
		    return ;   
    }
}


void parse_map(t_so_long *sl, int fd)
{
    init_sl(sl);
    fill_list_map(sl, fd);
    check_list(sl);
    free_list(&(sl->map));

}