#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <stdio.h>

# include "minirt_struct.h"
# include "mlx_utils.h"
# include "parser.h"
# include "utils.h"

# define USAGE "\x1b[31m[usage]\x1b[39m: ./miniRT ./scene/*.rt"
# define W_DISPLAY 800
# define H_DISPLAY 800

void	allocate_data(t_minirt_data *data);
void	free_all(t_minirt_data *data);
void	raytrace(t_minirt_data *data);

#endif /* MINIRT_H */