# include <fcntl.h>
# include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	int	pa[2];
	int	pid;

	if (pipe(pa) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	if (pid == 0)
	{
		int fd;

		fd = open(av[3], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (fd == -1)
			return (0);
		dup2(fd, 1);
		execve();
	}
	else
	{
		wait(NULL);
	}
}
