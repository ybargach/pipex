#include <stdio.h>
int main(int argc, char **argv, char **envp)
{
	char **all_path;
	char ***join_path;
	int i = 0;
    char *path;
    char *path1;
	int fd;
    int a = 0;
	int	you = 2;
	int ab = 0;
    while(envp[a])
    {
        if (strncmp(envp[a], "PATH=", 5) == 0)
            path = envp[a];
        a++;    
    }
	int cv = 0;
    char **paths = ft_split(path, ':');
	while (you < argc - 1)
	{
		path = ft_strjoin(paths[i], argv[you]);
		if (access(path, X_OK) == 0)
		{
			cv++;
 			break;
		}
		you++;
	}
	while (you < argc)
	{
		char **ls_args = ft_split(argv[you],' ');
		join_path[ab] = ls_args;
		ab++;
		you++;
	}
    //char **ls_args = ft_split(argv[2],' ');
    //char **wc_args = ft_split(argv[3],' ');
    while(paths && paths[i])
    {
        all_path = ft_strjoin(paths[i], join_path[you][0]);
        if (access(all_path, X_OK) == 0)
		{
			cv++;
 			break;
		}
        i++;
    }
}