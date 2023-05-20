/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:23:34 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 19:08:02 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_error(void)
{
	write(2, "Error about child\n", 18);
	exit(0);
}

void	exit_error(void)
{
	//ft_putstr_fd(str[a], 2);
	write(2, ": numeric argument required\n", 29);
	exit(0);
}

void	error_file(void)
{
	write(2, "Error File Descriptor\n", 22);
}

void	error_pipe(void)
{
	write(2, "There is problem in pipe\n", 25);
	exit(0);
}

void	error_code(void)
{
	write(2, "Command not found\n", 18);
}
