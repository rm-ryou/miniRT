#include "utils.h"

char	*free_path(char *for_free, char *new_ptr)
{
	free(for_free);
	for_free = NULL;
	return (new_ptr);
}
