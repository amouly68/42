#include "get_next_line.h"
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int fd;
	char *buffer;
	fd = open("test.txt", O_RDONLY);
	printf("%zd = ", read(fd, buffer, BUFFER_SIZE));
	printf("%s\n", buffer);
	printf("%zd = ", read(fd, buffer, BUFFER_SIZE));
	printf("%s\n", buffer);
	printf("%zd = ", read(fd, buffer, BUFFER_SIZE));
	printf("%s\n", buffer);
}
