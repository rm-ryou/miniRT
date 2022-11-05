#include "mlx_utils.h"

static int	on_destroy(t_minirt_data *minirt)
{
	destroy_mlx(minirt);
	free_all(minirt);
	exit(0);
	return (0);
}

static int	on_keydown(int keycode, t_minirt_data *minirt)
{
	if (keycode == 65307)
		on_destroy(minirt);
	return (0);
}

void	hooks(t_minirt_data *minirt)
{
	mlx_hook(minirt->mlx_win, 2, 1L << 0, on_keydown, minirt);
	mlx_hook(minirt->mlx_win, 17, 1L << 17, on_destroy, minirt);
}

void	destroy_mlx(t_minirt_data *minirt)
{
	mlx_destroy_image(minirt->mlx, minirt->img->img);
	mlx_destroy_window(minirt->mlx, minirt->mlx_win);
	free(minirt->mlx);
}