/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:49:00 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/16 20:50:00 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

char	*get_next_line(int fd);
char	*ft_strjoina(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strlen(const char *str);
char	*ft_read(char *stock, int fd);
char	*ft_line(char *str);
char	*ft_save(char *str);
char	*ft_strchr(char *str, int c);

#endif
