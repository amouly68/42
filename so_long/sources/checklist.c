#include "so_long.h"

int map_rectangle(t_so_long *sl)
{
    t_map   *head;

    head = sl->map;
    while(sl->map)
    {
        if (len_line(sl->map->line) != sl->map_width)
        {
            ft_printf("Error\nMap non rectangle\n");
            sl->map = head;
            return (0);
        }
        sl->map = sl->map->next;
    }
    sl->map = head;
    return(1);
}

int char_ok(t_so_long *sl)
{
    t_map   *head;

    head = sl->map;
    while(sl->map)
    {
        if (!(char_line_ok(sl->map->line,sl)))
        {
            ft_printf("Error\nMap non valide\n");
            sl->map = head;
            return (0);
        }
        sl->map = sl->map->next;
    }
   
    if (sl->collectible == 0 || sl->exit != 1 || sl->position != 1)
       {
            ft_printf("Error\nMap non valide\n");
            sl->map = head;
            return (0);
        }
    sl->map = head;
    return(1);
}


int check_list(t_so_long *sl)
{
    if (!(map_rectangle(sl)))
        return (0);
    if (!(char_ok(sl)))
        return (0);
    return (1);
}