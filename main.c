#include "pipex.h"

void	exec_child(char **paths, char **cmd, int *fd)
{
	int		i;

	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	i = -1;
	while (paths[++i])
		execve(paths[i], cmd, NULL);
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

	paths = NULL;
	if (argc < 5)
		ft_exit("Insufficient arguments");
	commands = parse_commands(argc, argv);
	file_to_stdin(argv[1]);
	if (pipe(fd) == -1)
		ft_exit("Unable to open pipe file descriptors");
	pid = fork();
	if (pid == 0)
	{
		paths = get_paths(envp, argv, 2);
		exec_child(paths, commands[0], fd);
	}
	waitpid(pid, NULL, 0);
	pid = fork();
	if (pid == 0)
	{
		paths = get_paths(envp, argv, 3);
		write_to_file(argv[4], fd, paths, commands[1]);
	}
	close(fd[0]);
	close(fd[1]);
	waitpid(pid, NULL, 0);
	ft_free_arr_arrs(commands);
	return (0);
}
