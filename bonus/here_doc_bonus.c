/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:20:05 by ybargach          #+#    #+#             */
/*   Updated: 2023/06/10 14:08:55 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	a;

	a = 0;
	while (s1[a] || s2[a])
	{
		if (!((unsigned char)s1[a] == (unsigned char)s2[a]))
			return ((unsigned char)s1[a] - (unsigned char)s2[a]);
		a++;
	}
	return (0);
}

void	create_parent_doc(int ac, char **av, t_pipex arr)
{
	if (arr.a == ac - 2)
	{
		arr.fd1 = open(av[ac - 1], O_CREAT | O_RDWR | O_APPEND, 0644);
		if (arr.fd1 == -1)
			error_file();
		dup2(arr.fd1, 1);
	}
	if ((access(av[arr.a], X_OK) == 0 && ft_strncmp(av[arr.a], "./", 2) == 0)
		|| ft_strncmp(av[arr.a], "./", 2) == 0
		|| ft_strncmp(av[arr.a], "/", 1) == 0)
	{
		arr.cmd = ft_split(av[arr.a], ' ');
		execve_path(av, arr);
	}
	if (ft_strncmp(av[arr.a], "exit", 4) == 0)
	{
		ft_isdigit(av[arr.a]);
		exit(1);
	}
	else
		access_function(av, arr);
}

int	here_child_doc(int ac, char **av, t_pipex arr)
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
		close_dup2(arr);
	return (arr.pid1);
}

int	here_doc(char **av, t_pipex arr)
{
	char	*p;
	char	*limiter;

	if (pipe(arr.p) == -1)
		error_pipe();
	limiter = ft_strjoin_her(av[2], "\n");
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		p = get_next_line(0);
		if (!p || (ft_strcmp(p, limiter) == 0))
			break ;
		write(arr.p[1], p, ft_strlen(p));
		free(p);
	}
	free(p);
	free(limiter);
	close(arr.p[1]);
	return (arr.p[0]);
}

void	pipex_here_doc(int ac, char **av, t_pipex arr)
{
	arr.c = 0;
	arr.d = 0;
	arr.exitstatus = malloc ((ac - 4) * (sizeof(int)));
	arr.exitarray = malloc ((ac - 4) * (sizeof(int)));
	arr.a = 3;
	arr.fd = here_doc(av, arr);
	dup2(arr.fd, 0);
	while (arr.a < ac - 1)
	{
		arr.exitarray[arr.c] = here_child_doc(ac, av, arr);
		arr.c++;
		arr.a++;
	}
	while (waitpid(arr.exitarray[arr.d], &arr.exit, 0) != -1)
	{
		if (WIFEXITED(arr.exit))
			arr.exitstatus[arr.d] = WEXITSTATUS(arr.exit);
		arr.d++;
	}
	exit(arr.exitstatus[arr.d - 1]);
}
