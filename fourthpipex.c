#include "pipex.h"

char	**check_path(char **envp, t_pipex arr)
{
	char	*path;
	char	**paths;

	arr.a = 0;
	while (envp[arr.a])
	{
		if (strncmp(envp[arr.a], "PATH=", 5) == 0)
			path = envp[arr.a];
		arr.a++;
	}
	paths = ft_split(path, ':');
	return (paths);
}

void	create_parent(int ac, char **av, t_pipex arr)
{
	if (arr.a == ac - 2)
	{
		arr.fd1 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0777);
		if (arr.fd1 == -1)
			error_file();
		dup2(arr.fd1, 1);
	}
	access_function(ac, av, arr);
}

void	create_child(int ac, char **av, t_pipex arr)
{
	if (pipe(arr.p) == -1)
		error_pipe();
	arr.pid1 = fork();
	if (arr.pid1 == -1)
		child_error();
	if (arr.pid1 == 0)
	{
		dup2(arr.p[1], 1);
		create_parent(ac, av, arr);
	}
	else
	{
		close_dup2(arr);
	}
}

void	access_function(int	ac, char **av, t_pipex arr)
{
	arr.b = 1;
	while (arr.path && arr.path[arr.b])
	{
		arr.cmd = ft_split(av[arr.a], ' ');
		arr.fcmd = ft_strjoin(arr.path[arr.b], arr.cmd[0]);
		if (access(arr.fcmd, X_OK) == 0)
		{
			arr.c++;
			execve_function(ac, av, arr);
		}
		close(arr.p[0]);
		close(arr.p[1]);
		arr.b++;		
	}
}

void	execve_function(int ac, char **av, t_pipex arr)
{
	close(arr.p[0]);
	close(arr.p[1]);
	arr.exe = execve(arr.fcmd, arr.cmd, arr.env);
	if (arr.exe == -1)
		error_execve();
}

int	main(int ac, char **av, char **env)
{
	t_pipex arr;

	arr.env = env;
	arr.a = 2;
	int der = 0;
	if (ac > 4)
	{
		arr.path = check_path(env, arr);
		if(strncmp(av[1], "here_dog", 8) == 0)
		{
			arr.a = 3;
			der++;
			here_dog(ac, av, arr);
		}
		dprintf(2, "done");
		if (der == 0)
		{
			arr.a = 2;
			arr.fd = open(av[1], O_RDONLY, 0777);
			if (arr.fd == -1)
				error_file();
			dup2(arr.fd, 0);
		}
		while (arr.a < ac - 1)
		{
			create_child(ac, av, arr);
			arr.a++;
		}
		while (wait(NULL) != -1)
			;
	}
	else
		write(1, "Error arg\n", 10);
}
