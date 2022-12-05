#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


void print_list(s_list *list)
{
	int a;

	a = 0;	
	while(list)
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
	static s_list *test;

	test = NULL;
	fill_node(&test, fd);
	fill_node(&test, fd);
	fill_node(&test, fd);
	fill_node(&test, fd);
	fill_node(&test, fd);
	fill_node(&test, fd);
	fill_node(&test, fd);
	print_list(test);
}
