#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
//#include "get_next_line.c"
//#include "get_next_line_utils.c"

void print_list(t_list *list)
{
	int a;

	a = 0;	
	while(list && list->str != NULL)
	{
		printf("noeud %d : %s\n",a , list->str);
	    a++;
		list = list->next;	
	}		
}

 int main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));

}
