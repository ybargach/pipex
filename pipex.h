#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct	pipex {
	int		a;
	int		b;
	int		c;
	int		len;
	int		p[2];
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


void	here_dog(int ac, char **av, t_pipex arr);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
void	access_function(int	ac, char **av, t_pipex arr);
void	execve_function(int ac, char **av, t_pipex arr);
void	child_error(void);
void	error_file(void);
void	error_pipe(void);
void	close_dup2(t_pipex arr);
void	error_execve(void);
void	error_code(void);
char	*get_next_line(int fd);
char	*ft_strjoina(char *s1, char *s2);
char	*ft_strdup(char *str);
int		ft_strlen(const char *str);
char	*ft_read(char *stock, int fd);
char	*ft_line(char *str);
char	*ft_save(char *str);
char	*ft_strchr(char *str, int c);
void	create_child(int ac, char **av, t_pipex arr);
int		ft_strlena(const char *str);

#endif
