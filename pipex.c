#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/wait.h>

int main(int argc, char const *argv[])
{
	unlink("result.txt");
	return 0;
}



// int main(int argc, char const *argv[])
// {
// 	int pipeline[2];
// 	pipe(pipeline);

// 	int d = fork();

// 	if(d == 0)
// 	{
// 		char c = 'a';
// 		write(pipeline[1], &c, 1);
// 		printf("send | %c | from child 1 files | %d | %d |\n", c, pipeline[0], pipeline[1]);
// 	}

// 	else{
// 		int k = fork();
// 		if(k == 0)
// 		{
// 			char x;
// 			read(pipeline[0], &x, 1);
// 			printf("recive | %c | from child 2 files | %d | %d |\n", x, pipeline[0], pipeline[1]);
// 		}
// 	}
// 	return 0;
// }
