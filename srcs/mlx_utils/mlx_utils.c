#include "mlx_utils.h"

void	my_mlx_pixel_put(t_img *imgs, int x, int y, int color)
{
	char	*dst;

	dst = imgs->addr + (y * imgs->line_length + x * (imgs->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_window(t_minirt_data *minirt)
{
	mlx_put_image_to_window(minirt->mlx, minirt->mlx_win, minirt->img->img, 0, 0);
	hooks(minirt);
	mlx_loop(minirt->mlx);
}

void	init_mlx(t_minirt_data *minirt)
{
	minirt->mlx = mlx_init();
	if (!minirt->mlx)
		put_message_exit("mlx_init error");
	minirt->mlx_win = mlx_new_window(minirt->mlx, W_DISPLAY, H_DISPLAY, "miniRT");
	minirt->img->img = mlx_new_image(minirt->mlx, W_DISPLAY, H_DISPLAY);
	minirt->img->addr = mlx_get_data_addr(minirt->img->img, &minirt->img->bits_per_pixel, &minirt->img->line_length, &minirt->img->endian);
}
