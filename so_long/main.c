
#include "so_long.h"

int main (int argc, char **argv)
{
    int fd;
    t_so_long   sl;
   
    
    if(!(check_error(argc, argv)))
        return (-1);
    init_sl(&sl);
    fd = open(argv[1], O_RDONLY);
    parse_map(&sl, fd);
    

    
}