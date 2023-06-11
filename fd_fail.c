/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_fail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:28:23 by ybargach          #+#    #+#             */
/*   Updated: 2023/06/05 19:56:55 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_exit_num(void)
{
	write(2, "exit: too many arguments\n", 25);
	exit(1);
}

void	num_error_exit(char *str)
{
	ft_putstr_fd(str, 2);
	write(2, ": numeric argument required\n", 29);
	exit(1);
}

void	error_file_1(int ac, char **av, t_pipex arr)
{
	arr.c = 0;
	arr.d = 0;
	arr.exitstatus = malloc ((ac - 4) * (sizeof(int)));
	arr.exitarray = malloc ((ac - 4) * (sizeof(int)));
	ft_putstr_fd(av[1], 2);
	write(2, ": No such file or directory\n", 29);
	arr.a++;
	if (pipe(arr.p) == -1)
		error_pipe();
	dup2(arr.p[0], 0);
	close(arr.p[1]);
	while (arr.a < ac - 1)
	{
		arr.exitarray[arr.c] = create_child_fail(ac, av, arr);
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

int	create_child_fail(int ac, char **av, t_pipex arr)
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
		close_dup2(arr);
	return (arr.pid1);
}
