#include "utils.h"

void	*x_malloc(size_t bytes)
{
	void	*memory;

	memory = malloc(bytes);
	if (memory == NULL)
		put_message_exit("out of virtual memory.");
	return (memory);
}