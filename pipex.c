
#include "pipex.h"

//  int main(int ac, char **av, char **envp)
// {
// 	int		a;
// 	int		b;
// 	int		i;
// 	int		j;
// 	int 	p[2];
// 	int		pid;
// 	int		pid2;
// 	int		fd;
// 	int		fd2;
// 	int		exe;
// 	int		exe2;
// 	char	*path;
// 	char	*path2;
// 	char	**paths;
// 	char	**first_cmd;
// 	char	**second_cmd;

// 	a = 0;
// 	b = 0;
// 	if (pipe(p) == -1)
// 		return (0);
// 	pid = fork();
// 	if (pid == -1)
// 		return (0);
// 	while (envp[a])
// 	{
// 		if (strncmp(envp[a] , "PATH=", 5) == 0)
// 			path = envp[a];
// 		a++;
// 	}
// 	paths = ft_split(path, ':');
// 	first_cmd = ft_split(av[2], ' ');
// 	second_cmd = ft_split(av[3], ' ');
// 	while (paths && paths[b])
// 	{
// 		path = ft_strjoin(paths[b], av[2]);
// 		if (access(path, X_OK) == 0)
// 		{
// 			i++;
// 			break;
// 		}
// 		b++;
// 	}
// 	b = 0;
// 	while(path[b])
// 	{
// 		path2 = ft_strjoin(paths[b], av[3]);
// 		if (access(path2, X_OK) == 0)
// 			break;
// 		b++;
// 	}
// 	if (pid == 0)
// 	{
// 		fd = open(av[1], O_RDWR, 0777);
// 		if (fd == -1)
// 			return (0);
// 		dup2(fd, 0);
// 		dup2(p[1], 1);
// 		close(p[0]);
// 		close(p[1]);
// 		exe = execve(path, first_cmd,envp);
// 		if (exe == -1)
// 			return (0);
// 	}
// 	else
// 	{
// 		wait(NULL);
// 		pid2 = fork();
// 		if (pid2 == -1)
// 			return (0);
// 		if (pid2 == 0)
// 		{
// 			fd2 = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
// 			if (fd2 == -1)
// 				return (0);
// 			dup2(fd2, 1);
// 			dup2(p[0], 0);
// 			close(p[0]);
// 			close(p[1]);
// 			exe2 = execve(path2, second_cmd,envp);
// 			if (exe2 == -1)
// 				return (0);
// 		}
// 		close(p[0]);
// 		close(p[1]);
// 	}
// }
