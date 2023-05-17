/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:23:34 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/16 22:15:01 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_error(void)
{
	write(2, "Error about child\n", 18);
	exit(0);
}

void	error_file(void)
{
	write(2, "Error File Descriptor\n", 22);
	//exit(0);
}

void	error_pipe(void)
{
	write(2, "There is problem in pipe\n", 25);
	exit(0);
}

void	error_execve(void)
{
	write(2, "Error : Not execve\n", 19);
}

void	error_code(void)
{
	write(2, "Command not found\n", 18);
}

void	close_dup2(t_pipex arr)
{
	dup2(arr.p[0], 0);
	close(arr.p[0]);
	close(arr.p[1]);
}
