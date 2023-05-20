/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:33:40 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:25 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**check_path(char **envp, t_pipex arr)
{
	char	*path;
	char	**paths;

	arr.a = 0;
	while (envp[arr.a])
	{
		if (ft_strncmp(envp[arr.a], "PATH=", 5) == 0)
			path = envp[arr.a];
		arr.a++;
	}
	paths = ft_split(path, ':');
	return (paths);
}

void	close_dup2(t_pipex arr)
{
	close(arr.p[1]);
	dup2(arr.p[0], 0);
	close(arr.p[0]);
}

void	ft_isdigit(char *str)
{
	int	a;

	a = 4;
	while (str[a])
	{
		if (str[a] >= '0' && str[a] <= '9')
		{
			if (str[a + 1] == '+' || str[a + 1] == '-')
				exit_error();
			if (str[a + 1] == ' ')
				write(2, "too many arguments\n", 19);
		}
		if (str[a] == '-' || str[a] == '+')
		{
			if (!(str[a + 1] >= '0' && str[a + 1] <= '9'))
				exit_error();
		}
		if (!((str[a] >= '0' && str[a] <= '9')
				|| str[a] == ' ' || str[a] == '+' || str[a] == '-'))
			exit_error();
		a++;
	}
}

void	create_parent(int ac, char **av, t_pipex arr)
{
	if (arr.a == ac - 2)
	{
		arr.fd1 = open(av[ac - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (arr.fd1 == -1)
			error_file();
		dup2(arr.fd1, 1);
	}
	if (access(av[arr.a], X_OK) == 0)
	{
		arr.cmd = ft_split(av[arr.a], ' ');
		execve_path(av, arr);
	}
	if (ft_strncmp(av[arr.a], "exit", 4) == 0)
	{
		ft_isdigit(av[arr.a]);
		exit(0);
	}
	else
		access_function(av, arr);
}

void	multi_pipex(int ac, char **av, t_pipex arr)
{
	arr.a = 2;
	arr.fd = open(av[1], O_RDONLY, 0644);
	if (arr.fd == -1)
		error_file_1(ac, av, arr);
	dup2(arr.fd, 0);
	while (arr.a < ac - 1)
	{
		create_child(ac, av, arr);
		arr.a++;
	}
	while (wait(NULL) != -1)
		;
}
