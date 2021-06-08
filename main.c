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
	char	***commands;
	int		i;
	pid_t	pid;

	i = 0;
	paths = NULL;
	if (argc < 5)
		ft_exit("Insufficient arguments");
	paths = get_paths(envp, argv);
	commands = parse_commands(argc, argv);
	for (int j = 0; commands[j]; j++)
	{
		int b = 0;
		while (commands[j][b])
		{
			printf("%s\n", commands[j][b]);
			b++;
		}
	}
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
	int j = -1;
	while (commands[++j])
		ft_freearrays(commands[j]);
	free(commands);
	return (0);
}
