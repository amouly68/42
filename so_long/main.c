
#include "so_long.h"

int main ()
{
    int fd;
    t_so_long   *sl;
   
    sl = malloc(sizeof(t_so_long *));
    if (sl == NULL)
        return (-1);
    fd = open("sources/test.ber", O_RDONLY);
    parse_map(sl, fd);
    free (sl);

    
}