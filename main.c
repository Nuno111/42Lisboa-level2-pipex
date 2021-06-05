#include "pipex.h"

void	ft_exit(char *err)
{
	if (err)
		printf("%s\n", err);
	exit(0);
}

int	main(int argc, char *argv[])
{
	char **paths;

	if (argc < 5)
		ft_exit("Insufficient arguments");
	paths = get_paths(paths);

}
