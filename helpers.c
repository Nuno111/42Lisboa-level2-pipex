#include "pipex.h"

char	**get_paths()
{
    int		fd;
	char	*line;
	char	**paths;
	char	*trimmed;

	line = NULL;
    fd = open("/etc/environment", O_RDONLY);
	if (fd == -1)
		ft_exit("Couldn't open file for reading");
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strncmp("PATH=", line, 5) == 0)
		{
			trimmed = ft_strtrim(line, "\"");
			paths = ft_split(&trimmed[6], ':');
			free(trimmed);
			return (paths);
		}
	}
	ft_exit("Couldn't find PATH environmental variable.");
	return (NULL);
}
