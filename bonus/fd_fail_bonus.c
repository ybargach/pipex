/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_fail_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:28:23 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:46 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	error_file_1(int ac, char **av, t_pipex arr)
{
	write(2, "No such file or directory\n", 27);
	if (pipe(arr.p) == -1)
		return ;
	dup2(arr.p[0], 0);
	close(arr.p[1]);
	while (arr.a < ac - 1)
	{
		create_child_fail(ac, av, arr);
		arr.a++;
	}
	exit(0);
}

void	create_child_fail(int ac, char **av, t_pipex arr)
{
	if (pipe(arr.p) == -1)
		error_pipe();
	arr.pid1 = fork();
	if (arr.pid1 == -1)
		child_error();
	if (arr.pid1 == 0)
	{
		close(arr.p[0]);
		dup2(arr.p[1], 1);
		create_parent(ac, av, arr);
	}
	else
	{
		close_dup2(arr);
		wait(NULL);
	}
}
