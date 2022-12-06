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

/*int main ()
{
	char str[] = "salut\nygdfweyugf\nbvedwnb";
	char *dest;
	printf("avant strim : %s\n", str);
	dest = trim_str(str);
	printf("apres strim : %s", dest);
}*/







/*int	main()
{
	int fd;
	fd = open("test.txt", O_RDONLY);
	
	static	s_list *stock;
	int		count;
	char	*line;

	stock = NULL;
	count = 0;
	while (!(check_new_line(stock, &count)))
	{
		if (!(fill_node(&stock, fd)))
		{
			print_list(stock);
			 printf("null");
			 return 0;
		}
	}
	print_list(stock);
	line = extract_line(stock, &count);
	printf("LINE : %s", line);
	trim_list(&stock);
	printf("APRES trim :\n");
	print_list(stock);
	count = 0;
	while (!(check_new_line(stock, &count)))
	{
		if (!(fill_node(&stock, fd)))
		{
			print_list(stock);
			 printf("null");
			 return 0;
		}
	}
	print_list(stock);
	line = extract_line(stock, &count);
	printf("LINE : %s", line);
	trim_list(&stock);
	printf("APRES trim :\n");
	print_list(stock);
}*/




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

}
