#include "pipex.h"

int	ft_strlena(const char *str)
{
	int	a;

	a = 0;
	if (!str)
		return (0);
	while (str[a])
		a++;
	return (a);
}

char	*ft_strdupa(char *str)
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
		return (ft_strdupa(""));
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
		return (ft_strdupa(""));
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

// int main(int argc, char **argv, char **envp) 
// {
//     int i = 0;
//     // Append directories to PATH environment variable
//     int p[2];
//     if(pipe(p) == -1)
//         return 0;
//     int pid = fork();
//     if (pid == -1)
//         return 0;
//     char *path;
//     char *path1;
//     int a = 0;
//     while(envp[a])
//     {
//         if (strncmp(envp[a], "PATH=", 5) == 0)
//             path = envp[a];
//         a++;    
//     }
//     char **paths = ft_split(path, ':');
//     char **ls_args = ft_split(argv[2],' ');
//     char **wc_args = ft_split(argv[3],' ');
//     while(paths && paths[i])
//     {
//         path = ft_strjoin(paths[i], ls_args[0]);
//         if (access(path, X_OK) == 0)
//             break;
//         i++;
//     }
//     i = 0;
//     while(paths && paths[i])
//     {
//         path1 = ft_strjoin(paths[i], wc_args[0]);
//         if (access(path1, X_OK) == 0)
//             break;
//         i++;
//     }
//     if (pid == 0)
//     {
//         int fd;

// 		fd = open(argv[1], O_RDWR , 0777);
//         dup2(fd, 0);
//         dup2(p[1], 1);
//         close(p[0]);
//         close(p[1]);
//         int ret = execve(path, ls_args , envp);
//        // printf("done\n");
//         if (ret == -1) 
//         {
//             return 1;
//         }
//     }
//     else
//     {
//         int pid2 = fork();
//         if (pid2 == 0)
//         {
//             int fd2;

// 		    fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0777);
//             dup2(fd2, 1);
//             dup2(p[0], 0);
//             close(p[0]);
//             close(p[1]);
//             int ret = execve(path1, wc_args , envp);
//             if (ret == -1) 
//             {
//                 printf("done\n");
//                 return 1;
//             }
//         }
//     }
//     // // Execute ls command
//     // printf("Executing ls command...\n");

//     // int ret = execve(path, ls_args , ls_envp);
// 	// printf("done\n");
//     // if (ret == -1) 
//     // {
//     //     printf("Failed to execute ls command\n");
//     //     return 1;
//     // }
//     close(p[0]);
//     close(p[1]);
//     while (!wait(NULL))
//         ;
    // // Execute wc command
    // char *wc_args[] = {"wc", "-w", "example.txt", NULL};
    // char *wc_envp[] = {"PATH=", new_path, NULL};
    // printf("Executing wc command...\n");
    // ret = execve("/usr/bin/wc", wc_args, wc_envp);
    // if (ret == -1) {
    //     printf("Failed to execute wc command\n");
    //     return 1;
    // }
    
    // // Execute cat command
    // char *cat_args[] = {"cat", "example.txt", NULL};
    // char *cat_envp[] = {"PATH=", new_path, NULL};
    // printf("Executing cat command...\n");
    // ret = execve("/bin/cat", cat_args, cat_envp);
    // if (ret == -1) {
    //     printf("Failed to execute cat command\n");
    //     return 1;
    // }
    
   // return 0;
//}

// int main(int argc, char **argv, char **envp) {
//     // Append directories to PATH environment variable
//     char *old_path = getenv("PATH");
//     char new_path[1024];
//     snprintf(new_path, sizeof(new_path), "%s:/bin:/usr/bin", old_path);
//     setenv("PATH", new_path, 1);
    
//     // Execute ls command
//     char *ls_args[] = {"ls", "-l", NULL};
//     printf("Executing ls command...\n");
//     int ret = execvp(ls_args[0], ls_args);
//     if (ret == -1) {
//         printf("Failed to execute ls command\n");
//         return 1;
//     }
    
//     // Execute wc command
//     char *wc_args[] = {"wc", "-w", "example.txt", NULL};
//     printf("Executing wc command...\n");
//     ret = execvp(wc_args[0], wc_args);
//     if (ret == -1) {
//         printf("Failed to execute wc command\n");
//         return 1;
//     }
    
//     // Execute cat command
//     char *cat_args[] = {"cat", "example.txt", NULL};
//     printf("Executing cat command...\n");
//     ret = execvp(cat_args[0], cat_args);
//     if (ret == -1) {
//         printf("Failed to execute cat command\n");
//         return 1;
//     }
    
//     return 0;
// }