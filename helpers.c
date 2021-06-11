#include "pipex.h"

void	file_to_stdin(char *file)
{
	int	file_fd;

	file_fd = open(file, O_RDONLY);
	if (file_fd == -1)
		ft_exit("Unable to open file for reading");
	dup2(file_fd, STDIN_FILENO);
	close(file_fd);
}

void	write_to_file(char *file_name, int *fd, char **paths, char **cmd)
{
	int		file_fd;
	int		i;

	file_fd = open(file_name, O_CREAT | O_TRUNC | O_WRONLY, 0777);
	if (file_fd == -1)
		ft_exit("Unable to open file for writing");
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	close(fd[1]);
	dup2(file_fd, STDOUT_FILENO);
	close(file_fd);
	i = -1;
	while (paths[++i])
		execve(paths[i], cmd, NULL);
}

char	***parse_commands(int argc, char **argv)
{
	char	***cmds;
	int		i;

	i = -1;
	cmds = malloc(sizeof(char **) * (argc - 1));
	if (!cmds)
		ft_exit("Unable to allocate memory for comands array");
	while (++i < argc - 3)
		cmds[i] = ft_split(argv[i + 2], ' ');
	cmds[i] = NULL;
	return (cmds);
}

static	void	finish_paths(char **paths, char **argv, int cmd_index)
{
	int		i;
	char	*tmp;
	char	**args;

	i = 0;
	while (paths[i])
	{
		ft_add_letter('/', &paths[i], false);
		tmp = paths[i];
		args = ft_split(argv[cmd_index], ' ');
		paths[i] = ft_strjoin(paths[i], args[0]);
		ft_freearrays(args);
		free(tmp);
		i++;
	}
}

char	**get_paths(char **envp, char **argv, int cmd_index)
{
	char	*line;
	char	**paths;
	int		i;

	line = NULL;
	i = -1;
	while (envp[++i])
	{
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
		{
			paths = ft_split(&envp[i][5], ':');
			free(line);
			finish_paths(paths, argv, cmd_index);
			return (paths);
		}
	}
	ft_exit("Couldn't find PATH environmental variable.");
	return (NULL);
}
