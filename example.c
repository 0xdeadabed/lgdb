#include	<stdio.h>
#include	<unistd.h>

# define	FILE_WRITE	1	// write
# define	FILE_READ	0	// read

int	main()
{
	int	fd[2];
	int	id;

	printf("start program\n");
	
	if (pipe(fd) == -1)
		printf("Error, pipe\n");

	id = fork();

	printf("Hello world from %d\n",id);

	// child
	if (id == 0)
	{
		sleep(1);
		close(fd[FILE_READ]);
		printf("child\n");
		int	x;
		printf("enter number :");
		scanf("%d", &x);
		write(fd[FILE_WRITE], &x, sizeof(int));
		close(fd[FILE_WRITE]);
	}

	// parent
	else
	{
		printf("parent\n");
		close(fd[FILE_WRITE]);
		int	y;
		read(fd[FILE_READ], &y, sizeof(int));
		printf("number : %d\n", y);
		close(fd[FILE_READ]);
	}
	return (0);
}
