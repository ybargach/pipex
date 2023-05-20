/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 17:33:49 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:48:32 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	child_error(void)
{
	write(2, "Error about child\n", 18);
	exit(0);
}

void	exit_error(void)
{
	write(2, "numeric argument required\n", 27);
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
