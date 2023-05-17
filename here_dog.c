#include "pipex.h"

void	create_parent_doc(int ac, char **av, t_pipex arr)
{
	if (arr.a == ac - 2)
	{
		arr.fd1 = open(av[ac - 1], O_CREAT | O_RDWR , 0777);
		if (arr.fd1 == -1)
			error_file();
		dup2(arr.fd1, 1);
		access_function(ac, av, arr);
	}
}

void	pipe_doc(int ac, char **av, t_pipex arr)
{
	arr.a = 2;
	while (arr.a < ac - 1)
	{
		if (pipe(arr.p) == -1)
			error_pipe();
		arr.pid1 = fork();
		if (arr.pid1 == -1)
			child_error();
		if (arr.pid1 == 0)
		{
			dup2(arr.p[1], 1);
			create_parent_doc(ac, av, arr);
		}
		else
		{
			close_dup2(arr);
			while (wait(NULL) != -1)
				;
		}
		arr.a++;
	}
}

void	here_dog(int ac, char **av, t_pipex arr)
{
	int	a;
	int b;
	a = 2;
	char *s;
	char *p;
	arr.a = 2;
	arr.fd = open(av[1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (arr.fd == -1)
		error_file();
	//dup2(arr.fd, 1);
	p = get_next_line(0);
	arr.len = ft_strlena(av[2]);
	while (1)
	{
		p = get_next_line(0);
		if (!p || strncmp(p, av[2], 4) == 0)
			break ;
		write(arr.fd, p, ft_strlen(p));
		free(p);
	}
}