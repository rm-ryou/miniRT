#ifndef MLX_UTILS_H
#define MLX_UTILS_H

# include "mlx.h"
# include "minirt_struct.h"
# include "utils.h"

void	destroy_mlx(t_minirt_data *minirt);
void	draw_window(t_minirt_data *minirt);
void	hooks(t_minirt_data *minirt);
void	init_mlx(t_minirt_data *minirt);
void	my_mlx_pixel_put(t_img *imgs, int x, int y, int color);

#endif /* MLX_UTILS_H */