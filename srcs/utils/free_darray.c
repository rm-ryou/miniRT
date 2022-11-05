#include "utils.h"

void	free_darray(char **darray)
{
	int	i;

	i = 0;
	while (darray[i])
	{
		free(darray[i]);
		darray[i] = NULL;
		i++;
	}
	free(darray);
	darray = NULL;
}
