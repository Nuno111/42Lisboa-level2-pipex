#include "pipex.h"

void	get_paths(char **paths)
{
    int		fd;
	char	*line;

	line = NULL;
    fd = open("/etc/environment", O_RDONLY);
	if (fd == -1)
		ft_exit("Couldn't open file for reading");
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp("PATH=", line, 5))
		{
			paths = ft_split(line, ':');
			break;
		}
	}
	if (!paths)
		ft_exit("Couldn't find PATH environmental variable.");
}
