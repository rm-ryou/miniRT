#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# include "libft.h"
# include "minirt.h"

int		x_open(char *filepath);
double	get_double(char *str_double);
char	*free_path(char *for_free, char *new_ptr);
void	free_darray(char **darray);
void	put_message_exit(char *str);
void	*x_malloc(size_t bytes);
void	free_all(t_minirt_data *minirt);

#endif // !UTILS_H