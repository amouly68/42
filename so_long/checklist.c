#include "so_long.h"

int map_rectangle(t_so_long *sl)
{
    t_map   *head;

    head = sl->map;
    while(sl->map)
    {
        if (len_line(sl->map->line) != sl->map_width)
        {
            ft_printf("Error\nmap non rectangle\n");
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
        if (!(char_line_ok(sl->map->line)))
        {
            ft_printf("Error\nCarcatere non reconnu\n");
            return (0);
        }
        sl->map = sl->map->next;
    }
    sl->map = head;
    return(1);
}


void    check_list(t_so_long *sl)
{
    if (!(map_rectangle(sl)))
        return ;
    if (!(char_ok(sl)))
        return ;
    print_list(sl->map);
}