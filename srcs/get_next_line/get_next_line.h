#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>

# include "libft.h"
# include "utils.h"

# define BUFFER_SIZE 42

char	*get_next_line(int fd);

#endif /* GET_NEXT_LINE_H */
