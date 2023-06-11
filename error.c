/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:23:34 by ybargach          #+#    #+#             */
/*   Updated: 2023/06/04 15:21:17 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_error(void)
{
	write(2, "Error about Fork\n", 18);
	exit(1);
}

void	exit_error(void)
{
	write(2, ": numeric argument required\n", 29);
	exit(1);
}

void	error_file(void)
{
	write(2, "Error File Descriptor\n", 22);
	exit(1);
}

void	error_pipe(void)
{
	write(2, "There is problem in pipe\n", 25);
	exit(1);
}

void	error_code(void)
{
	write(2, "Command not found\n", 18);
	exit(127);
}
