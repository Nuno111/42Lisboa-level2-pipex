#include "pipex.h"

void	ft_exit(char *err)
{
	if (err)
		printf("%s\n", err);
	exit(0);
}

int	main(int argc, char *argv[], char **envp)
{
	char	**paths;
	int		i;
	pid_t	pid;

	i = 0;
	paths = NULL;
	if (argc < 5)
		ft_exit("Insufficient arguments");
	paths = get_paths(envp, argv);
	pid = fork();
	char *argm[] = {"ls", "-l", NULL};
	while (paths[i])
	{
		if (pid == 0)
			execve(paths[i], argm, NULL);
		else
			printf("%s\n", paths[i]);
		i++;
	}
	ft_freearrays(paths);
	return (0);
}
