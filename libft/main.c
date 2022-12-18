#include <stdio.h>
#include "libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd;
	
	fd = open("text.txt", O_RDONLY);
	
	printf("essai printf 45 = %d\n", 45);	
	ft_printf("essai ft_printf 45 = %d\n", 45);	
	ft_printf("%s", get_next_line(fd));	
	ft_printf("%s", get_next_line(fd));	
	ft_printf("%s", get_next_line(fd));	
	ft_printf("%s", get_next_line(fd));	
	ft_printf("%s", get_next_line(fd));	
	ft_printf("%s", get_next_line(fd));	
		
}
