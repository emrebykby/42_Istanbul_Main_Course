#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	printf("PID: %d", getpid());

	while(1)
	{
		pause();
	}
}
