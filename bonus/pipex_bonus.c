/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:20:25 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:46:45 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	execve_path(char **av, t_pipex arr)
{
	close(arr.p[0]);
	close(arr.p[1]);
	arr.exe = execve(av[arr.a], arr.cmd, arr.env);
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
		wait(NULL);
	}
}

void	access_function(char **av, t_pipex arr)
{
	arr.b = 1;
	arr.c = 0;
	while (arr.path && arr.path[arr.b])
	{
		arr.cmd = ft_split(av[arr.a], ' ');
		arr.fcmd = ft_strjoin(arr.path[arr.b], arr.cmd[0]);
		if (access(arr.fcmd, X_OK) == 0)
			break ;
		arr.b++;
	}
	execve_function(arr);
	close(arr.p[0]);
	close(arr.p[1]);
}

void	execve_function(t_pipex arr)
{
	close(arr.p[0]);
	close(arr.p[1]);
	arr.exe = execve(arr.fcmd, arr.cmd, arr.env);
	if (arr.exe == -1)
		write(2, "Command not found:\n", 19);
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	arr;

	arr.env = env;
	arr.c = 0;
	if (ac > 4)
	{
		arr.path = check_path(env, arr);
		if (ft_strcmp(av[1], "here_doc" ) == 0 && ac > 5)
			pipex_here_doc(ac, av, arr);
		else
			multi_pipex(ac, av, arr);
	}
	else
		write(1, "Error arg\n", 10);
	return (0);
}
