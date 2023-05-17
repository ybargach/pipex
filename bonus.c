# include <fcntl.h>
# include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv, char **envp) 
{
    // int i = 0;
    // char *path;
	// char *all_path;
	// char **join_path;
    // char *path1;
	// int fd;
	// char ***ls_args;
    // int a = 0;
    // while(envp[a])
    // {
    //     if (strncmp(envp[a], "PATH=", 5) == 0)
    //         path = envp[a];
    //     a++;    
    // }
	// int cv = 0;
    // //char **paths = ft_split(path, ':');
	// int you = 2;
	// int	ab = 0;
    // while (you < argc - 1)
	// {
	// 	ls_args[ab] = ft_split(argv[you],' ');
	// 	ab++;
	// 	you++;
	// }
	// int p[argc - 3][2];
	// a = 0;
	// int b;
	// while(a < (argc - 3))
	// {
	// 	if(pipe(p[a]) == -1)
	// 	{
	// 		b = a;
	// 		while(b < 0)
	// 		{
	// 			close(p[b][0]);
	// 			close(p[b][1]);
	// 			b--;
	// 		}
	// 		exit (0);
	// 	}
	// 	a++;
	// }
    // int pid = fork();
    // if (pid == -1)
    //     return 0;
	// if (pid == 0)
	// {
	// 	int popen = 0;
	// 	fd = open(argv[1], O_RDONLY , 0777);
	// 	if (fd == -1)
	// 	{
	// 		write(1, "file not found\n", 15);
	// 		exit(0);
	// 	}
        //dup2(fd, 0);
		//a = 0;
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
		//you = 0;
		//int ret;
		// while(you < ab - 1)
		// {
		// 	i = 0;
		// 	while(paths && paths[i])
		// 	{
		// 		all_path = ft_strjoin(paths[i], ls_args[you][0]);
		// 		if (access(all_path, X_OK) == 0)
		// 		{
		// 			int id1 = fork();
		// 			if (id1 == 0)
		// 			{
		// 				ret = execve(all_path, ls_args[you] , envp);
		// 				if (ret == -1)
		// 				{
		// 					printf("command not run");
		// 					return 0;
		// 				}
		// 			}

		// 		}
		// 		i++;
		// 	}
		// 	you++;
		// }
	}
	else
	{
		int pid2 = fork();
        if (pid2 == 0)
        {
            int fd2;

			if (cva == 0)
				fd2 = open(argv[4], O_CREAT | O_RDONLY | O_TRUNC, 0777);
			else
		    	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0777);
			if (fd2 == -1)
				return (0);
			
	}

}

}