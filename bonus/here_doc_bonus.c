/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 10:20:05 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:49:39 by ybargach         ###   ########.fr       */
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
	access_function(av, arr);
}

void	here_child_doc(int ac, char **av, t_pipex arr)
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
		wait(NULL);
	}
}

int	here_doc(char **av, t_pipex arr)
{
	char	*p;

	if (pipe(arr.p) == -1)
		return (-1);
	while (1)
	{
		ft_putstr_fd("here_doc > ", 1);
		p = get_next_line(0);
		if (!p || (strncmp(p, av[2], 2) == 0))
			break ;
		write(arr.p[1], p, ft_strlen(p));
		free(p);
	}
	free(p);
	close(arr.p[1]);
	return (arr.p[0]);
}

void	pipex_here_doc(int ac, char **av, t_pipex arr)
{
	arr.a = 3;
	arr.fd = here_doc(av, arr);
	if (dup2(arr.fd, 0))
		perror("failed :");
	while (arr.a < ac - 1)
	{
		here_child_doc(ac, av, arr);
		arr.a++;
	}
	while (wait(NULL) != -1)
		;
	exit(0);
}
