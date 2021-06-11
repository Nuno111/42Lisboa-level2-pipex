#include "libft.h"

void	ft_free_arr_arrs(char ***arrs)
{
	int	i;

	i = -1;
	while (arrs[++i])
		ft_freearrays(arrs[i]);
	free(arrs);
	arrs = NULL;
}
