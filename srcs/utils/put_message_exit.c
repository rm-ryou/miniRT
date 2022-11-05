#include "utils.h"

void	put_message_exit(char *str)
{
	printf("Error\n");
	printf("\x1b[31m%s\x1b[39m\n", str);
	exit(1);
}
