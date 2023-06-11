/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:20:25 by ybargach          #+#    #+#             */
/*   Updated: 2023/06/05 20:14:28 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execve_path(char **av, t_pipex arr)
{
	close(arr.p[0]);
	close(arr.p[1]);
	arr.exe = execve(av[arr.a], arr.cmd, arr.env);
	if (arr.exe == -1)
	{
		ft_putstr_fd(*arr.cmd, 2);
		write(2, ": Command not found\n", 20);
	}
	exit(127);
}

int	create_child(int ac, char **av, t_pipex arr)
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
		close_dup2(arr);
	return (arr.pid1);
}

void	access_function(char **av, t_pipex arr)
{
	arr.b = 1;
	arr.c = 0;
	arr.cmd = ft_split(av[arr.a], ' ');
	while (arr.path && arr.path[arr.b])
	{
		arr.fcmd = ft_strjoin(arr.path[arr.b], arr.cmd[0]);
		if (access(arr.fcmd, X_OK) == 0)
			break ;
		free(arr.fcmd);
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
	{
		ft_putstr_fd(*arr.cmd, 2);
		write(2, ": Command not found\n", 20);
	}
	exit(127);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	arr;

	arr.env = env;
	arr.c = 0;
	if (ac == 5)
	{
		arr.path = check_path(env, arr);
		multi_pipex(ac, av, arr);
	}
	else
	{
		write(2, "Error arg\n", 10);
		exit (1);
	}
	return (0);
}
