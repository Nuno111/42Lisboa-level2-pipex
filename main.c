#include "pipex.h"

void	ft_exit(char *err)
{
	if (err)
		printf("%s\n", err);
	exit(0);
}

int	main(int argc, char *argv[])
{
	char	**paths;
	char	*tmp;

	paths = NULL;
	if (argc < 5)
		ft_exit("Insufficient arguments");
	paths = get_paths();
	int i = 0;
	while (paths[i])
	{
		ft_add_letter('/', &paths[i], false);
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], argv[2]);
		free(tmp);
		char *argm[] = {"ls", "-l", NULL};
		execve(paths[i], argm, NULL);
		printf("%s\n", paths[i]);
		i++;
	}
	ft_freearrays(paths);
	return (0);
}
