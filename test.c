#include "libft.h"
#include <sys/types.h>
#include <sys/wait.h>

int	main(void)
{
	pid_t pid;
	int		fd[2];

	pipe(fd);
	pid = fork();

	if (pid == 0)
	{
		char *arr[] = {"ls", NULL};
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/ls", arr, NULL);
	}
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid == 0)
	{
		char *arr[] = {"grep", "pipex", NULL};
		int file = open("myfile", O_CREAT | O_WRONLY, 0777);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		dup2(file, STDOUT_FILENO);
		close(file);
		execve("/usr/bin/grep", arr, NULL);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	return 0;
}
