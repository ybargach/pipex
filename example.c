#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	int	p1[2]; // C => P
	int	p2[2]; // P => C
	int	id;

	if (pipe(p1) == -1)
		return 1;
	if (pipe(p2) == -1)
		return 2;
	id = fork();
	if (id == -1)
		return 3;
	if (id == 0)
	{
		close(p1[0]);
		close(p2[1]);
		int	x;
		if (read(p2[0], &x, sizeof(x)) == -1)
		{
			perror("close");
			return 4;
		}
		printf("child test 1 == %d\n", x);
		x *= 4;
		if (write(p1[1], &x, sizeof(x)) == -1)
		{
			perror("close");
			return 5;
		}
		printf("child test 2 == %d\n", x);
		close(p2[0]);
		close(p1[1]);
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		int y = rand() % 10;
		if (write(p2[1], &y, sizeof(y)) == -1)
		{
			perror("close");
			return 6;
		}
		printf("parent test 1 === %d\n", y);
		if (read(p1[0], &y, sizeof(y)) == -1)
		{
			perror("close");
			return 7;
		}
		printf("parent test 2 === %d\n", y);
		close(p1[0]);
		close(p2[1]);
		wait(NULL);
	}
	return 0;
}
