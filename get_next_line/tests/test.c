#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int	main()
{
	int fd;
	int i = 0;
	char *c = (char *)malloc(sizeof(char) * 4);

	fd = open("test.txt", O_RDONLY);
	read(fd, c, 100);

	printf("sonuç >> %s", c);
}
