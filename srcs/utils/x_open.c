#include "utils.h"

int	x_open(char *filepath)
{
	int	fd;

	fd = open(filepath, O_RDONLY);
	if (fd == -1)
		put_message_exit("can't open file.");
	return (fd);
}
