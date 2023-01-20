#include "so_long.h"

int len_line(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
        i++;
    return (i);
}

int char_line_ok(char *line)
{
    int i;

    i = 0;
    while(line[i] != '\n' && line[i] != '\0')
    {
        if (line[i] != '0' && line[i] != '1' 
            && line[i] != 'C' && line[i] != 'E'
            && line[i] != 'P')
                return (0);
        i++;
    }
    return (1);
}


int all_one(char *line)
{
    int i;

    i = 0;
    while(line[i])
    {
        if (line[i] != '1')
            return (0);
        i++;
    }
    return (1);
}
