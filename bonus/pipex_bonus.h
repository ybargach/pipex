/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:12:29 by ybargach          #+#    #+#             */
/*   Updated: 2023/05/20 17:32:57 by ybargach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct pipex {
	int		a;
	int		b;
	int		c;
	int		len;
	int		p[2];
	int		pid;
	int		pid1;
	int		fd;
	int		fd1;
	int		ac;
	int		exe;
	char	*fcmd;
	char	**cmd;
	char	**av;
	char	**env;
	char	**path;
	char	**paths;
}	t_pipex;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// here_dog

void	ft_putstr_fd(char *s, int fd);
void	pipex_here_doc(int ac, char **av, t_pipex arr);
int		here_doc(char **av, t_pipex arr);
void	here_child_doc(int ac, char **av, t_pipex arr);
void	create_parent_doc(int ac, char **av, t_pipex arr);
int		ft_strcmp(char *s1, char *s2);

// multi pipe

void	execve_path(char **av, t_pipex arr);
void	access_function(char **av, t_pipex arr);
void	execve_function(t_pipex arr);
void	create_child(int ac, char **av, t_pipex arr);
void	create_parent(int ac, char **av, t_pipex arr);
void	multi_pipex(int ac, char **av, t_pipex arr);
void	close_dup2(t_pipex arr);

// check and error

void	create_child_fail(int ac, char **av, t_pipex arr);
int		ft_strncmp(const char *s1, const char *s2, int n);
void	exit_error(void);
void	ft_isdigit(char *str);
char	**check_path(char **envp, t_pipex arr);
char	*ft_strjoin(char const *s1, char const *s2);
void	child_error(void);
void	error_file(void);
void	error_file_1(int ac, char **av, t_pipex arr);
void	error_pipe(void);
void	error_code(void);

//get_next_line && split

char	*get_next_line(int fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin_get(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strlen(const char *str);
char	*ft_read(char *stock, int fd);
char	*ft_line(char *str);
char	*ft_save(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
char	*ft_strtrim(char const *s1, char const *set);

#endif
