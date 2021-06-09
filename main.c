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
	int		fd[2];
	pid_t	pid;
	int		outfile;

	i = 0;
	paths = NULL;
	if (argc < 5)
		ft_exit("Insufficient arguments");
	paths = get_paths(envp, argv);
	commands = parse_commands(argc, argv);
	outfile = open(argv[argc], O_WRONLY | O_CREAT, 0777);
	if (outfile == -1)
		ft_exit("Unable to open output file for writing");
	if (pipe(fd) == -1)
		ft_exit("Unable to open pipe file descriptors");
	pid = fork();
	while (paths[i])
	{
		if (pid == 0)
		{
			dup2(fd[1], STDOUT_FILENO);


			execve(paths[i], argm, NULL);
		}
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
