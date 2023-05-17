# include <fcntl.h>
# include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_strlen(const char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

char	*ft_strdup(char *str)
{
	int		a;
	int		b;
	char	*p;

	if (!str)
		return (NULL);
	p = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!p)
		return (NULL);
	a = 0;
	b = 0;
	while (str[a])
		p[b++] = str[a++];
	p[b] = '\0';
	return (p);
}
int	first(char const *s1, char const *s2)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	while (s1[a] && s2[b])
	{
		if (s1[a] == s2[b])
		{
			b = 0;
			a++;
		}
		else if (s1[a] != s2[b])
			b++;
	}
	return (a);
}

int	last(char const *s1, char const *s2)
{
	int	a;
	int	b;

	a = (int)ft_strlen(s1) - 1;
	b = 0;
	while (s1[a] && s2[b])
	{
		if (s1[a] == s2[b])
		{
			b = 0;
			a--;
		}
		else if (s1[a] != s2[b])
			b++;
	}
	return (a);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		a;
	int		b;
	int		c;
	int		size;
	char	*p;

	if (!s1 || !set)
		return (0);
	a = first(s1, set);
	b = last(s1, set);
	c = 0;
	if (a == (int)ft_strlen(s1))
		return (ft_strdup(""));
	else
		size = b - a + 1;
	p = malloc((size + 1) * sizeof(char));
	if (!p)
		return (0);
	while (a <= b)
		p[c++] = s1[a++];
	p[c] = '\0';
	return (p);
}

int	word(char const *str, char c)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[a])
	{
		while (str[a] == c && str[a])
		{
			a++;
		}
		while (str[a] != c && str[a])
		{
			a++;
		}
		count++;
	}
	return (count);
}

int	start(char *str, char c, int i)
{
	while (str[i] == c && str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*p;
	unsigned int	a;
	unsigned int	b;

	a = start;
	b = 0;
	if (!s)
		return (0);
	if (len > (size_t)ft_strlen(s))
		len = (unsigned int)ft_strlen(s) - start;
	if (start > (unsigned int)ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (0);
	while (s[a] && b < len)
	{
		p[b] = s[a];
		a++;
		b++;
	}
	p[b] = '\0';
	return (p);
}

int	end(char *str, char c, int i)
{
	while (str[i] != c && str[i])
	{
		i++;
	}
	return (i);
}

char	*trim(char const *s, char c)
{
	char	*t;
	char	*str;

	if (!s)
		return (0);
	t = (char *)malloc(2 * sizeof(char));
	if (!t)
		return (0);
	t[0] = c;
	t[1] = '\0';
	str = ft_strtrim(s, t);
	free(t);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	char	*str;
	int		b;
	int		x;
	int		y;

	if (!s)
		return (0);
	str = trim(s, c);
	b = 0;
	x = 0;
	y = 0;
	p = (char **)malloc((word(str, c) + 1) * sizeof(char *));
	if (!p || !str)
		return (0);
	while (b < word(str, c))
	{
		x = start(str, c, y);
		y = end(str, c, x);
		p[b] = ft_substr(str, x, (y - x));
		b++;
	}
	p[b] = NULL;
	free(str);
	return (p);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	d;
	size_t	lendst;
	size_t	lensrc;

	if (!dst && !dstsize)
		return (ft_strlen(src));
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	d = 0;
	if (dstsize == 0)
		return (lensrc);
	if (dstsize < lendst)
		return (lensrc + dstsize);
	a = lendst;
	while (src[d] && dstsize - 1 > a)
	{
		dst[a] = src[d];
		d++;
		a++;
	}
	dst[a] = '\0';
	return (lendst + lensrc);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		d;
	int		a;
	int		b;

	if (!s1 || !s2)
		return (0);
	d = (ft_strlen(s1) + ft_strlen(s2) + 2);
	a = 0;
	b = 0;
	p = malloc(d * sizeof(char));
	if (!p)
		return (0);
	while (s1[b] && d - 1 > a)
	{
		p[a] = s1[b];
		a++;
		b++;
	}
	p[a++] = '/';
    p[a] = '\0';
	ft_strlcat(p, s2, d);
	return (p);
}

int main(int argc, char **argv, char **envp) 
{
    int i = 0;
    // Append directories to PATH environment variable
    char *path;
	char *all_path;
	char **join_path;
    char *path1;
	int fd;
	char ***ls_args;
    int a = 0;
    while(envp[a])
    {
        if (strncmp(envp[a], "PATH=", 5) == 0)
            path = envp[a];
        a++;    
    }
	int cv = 0;
    char **paths = ft_split(path, ':');
	int you = 2;
	int	ab = 0;
    while (you < argc - 1)
	{
		ls_args[ab] = ft_split(argv[you],' ');
		ab++;
		you++;
	}
		you = 0;
	while(you < ab - 1)
	{
		i = 0;
		while(paths && paths[i])
		{
			all_path = ft_strjoin(paths[i], ls_args[you][0]);
			if (access(all_path, X_OK) == 0)
			{
				//join_path = all_path;
				dprintf(2, " first == %s\n", all_path);
				cv++;
				break;
			}
			i++;
		}
		you++;
	}

	// i = 0;
	// while(all_path[i])
	// {
	// 	dprintf(2, "%s\n", all_path[i]);
	// 	i++;
	// }
	exit(0);
	int cva = 0;
	// while(paths && paths[i])
	// {
	// 	path1 = ft_strjoin(paths[i], wc_args[0]);
	// 	if (access(path1, X_OK) == 0)
	// 	{
	// 		cva++;
	// 		break;
	// 	}
	// 	i++;
	// }
	if (cv == 0 || cva == 0)
	{
		if (cv == 0)
			printf("command not found: %s\n", argv[2]);
		if (cva == 0)
			printf("command not found: %s", argv[3]);
	}
	int p[argc - 3][2];
	a = 0;
	int b;
	while(a < (argc - 3))
	{
		if(pipe(p[a]) == -1)
		{
			b = a;
			while(b < 0)
			{
				close(p[b][0]);
				close(p[b][1]);
				b--;
			}
			exit (0);
		}
		a++;
	}
    int pid = fork();
    if (pid == -1)
        return 0;
    if (pid == 0)
    {
		int popen = 0;
		fd = open(argv[1], O_RDONLY , 0777);
		if (fd == -1)
		{
			write(1, "file not found\n", 15);
			exit(0);
		}
        dup2(fd, 0);
		a = 0;
		while (a < argc - 3)
		{
			if (a == popen)
			{
				dup2(p[a][1], 1);
				popen++;
			}
			a++;
		}
		a = 0;
		while (a < argc)
		{
			close(p[a][0]);
			close(p[a][1]);
			a++;
		}
		you = 0;
		int ret;
		while(you < ab - 1)
		{
			int pid3 = fork();
			if (pid3 == 0)
			{
        		ret = execve(path, ls_args[you] , envp);
				if (ret == -1)
				{
					printf("command not run");
					return 0;
				}
			}
			you++;
		}
        if (ret == -1) 
        {
            return 1;
        }
    }
	else
	{
		int popen = 0;
		int pid2 = fork();
		if (pid2 == 0)
		{
			int fd2;

			if (cva == 0)
				fd2 = open(argv[argc - 1], O_CREAT | O_RDONLY | O_TRUNC, 0777);
			else
				fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0777);
			if (fd2 == -1)
				return (0);
			dup2(fd2, 1);
			a = 0;
			while (a < argc - 3)
			{
				if (a == popen)
				{
					dup2(p[a][0], 0);
					popen++;
				}
				a++;
			}
			dprintf(2, "%d\n", popen);
			a = 0;
			while (a < argc - 3)
			{
				close(p[a][0]);
				close(p[a][1]);
				a++;
			}
			int ret = execve(path1, ls_args[argc - 1] , envp);
			if (ret == -1) 
			{
				printf("done\n");
				return 1;
			}
		}
}
		a = 0;
    	while (a < argc - 3)
		{
			close(p[a][0]);
			close(p[a][1]);
			a++;
		}
	wait(NULL);
	wait(NULL);
   return 0;
}
