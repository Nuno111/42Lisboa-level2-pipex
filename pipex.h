#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include "unistd.h"

void	ft_exit(char *err);
char	**get_paths(char **envp, char **argv);
char ***parse_commands(int argc, char **argv);

# endif
