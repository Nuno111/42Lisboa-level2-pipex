#include "pipex.h"

void	exec_child(char **paths, char **cmd, int *fd)
{
	int		i;

	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	i = -1;
	while (paths[++i])
		execve(paths[i], cmd, NULL);
}

void	exec_normal_child(char **paths, char **argv, int *fd)
{
	int		i;
	char	*cmds;


	cmds =

	i = -1;
	while (paths[++i])
		execve(paths[i], cmds, NULL);

}

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

	i = -1;
	paths = NULL;
	if (argc < 5)
		ft_exit("Insufficient arguments");
	commands = parse_commands(argc, argv);
	if (pipe(fd) == -1)
		ft_exit("Unable to open pipe file descriptors");
	while (++i < argc - 4)
	{
		pid = fork();
		if (pid == -1)
			ft_exit("Unable to fork new process");
		if (pid == 0)
		{
			paths = get_paths(envp, argv, i);
			exec_child(paths, commands[i], fd);
			free_array_arrays(paths);
		}
		waitpid(pid, NULL, 0);
	}
	return (0);
}
