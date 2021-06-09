#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "unistd.h"
# include <sys/wait.h>

void	ft_exit(char *err);
char ***parse_commands(int argc, char **argv);
char	**get_paths(char **envp, char **argv, int cmd_index);

# endif
