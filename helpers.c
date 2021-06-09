#include "pipex.h"

char ***parse_commands(int argc, char **argv)
{
	char	***cmds;
	char	*tmp;
	char	*tmp_cmd;
	int		i;

	i = -1;
	cmds = malloc(sizeof(char **) * (argc - 1));
	if (!cmds)
		ft_exit("Unable to allocate memory for comands array");
	while (++i < argc - 2)
	{
		if (i == 0)
		{
			tmp = ft_strjoin(argv[2], ' ');
			tmp_cmd = ft_strjoin(tmp, argv[1]);
			cmds[i] = ft_split(tmp_cmd, ' ');
			free(tmp);
			free(tmp_cmd);
		}
		else
			cmds[i] = ft_split(argv[i + 2], ' ');
	}
	cmds[i] = NULL;
	return (cmds);
}

static	void	finish_paths(char **paths, char **argv, int cmd_index)
{
	int		i;
	char	*tmp;


	i = 0;
	while (paths[i])
	{
		ft_add_letter('/', &paths[i], false);
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], argv[cmd_index]);
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
