#include "minirt.h"

int	main(int argc, char *argv[])
{
	t_minirt_data	minirt;

	if (argc != 2)
		put_message_exit("\x1b[34mUSAGE\x1b[39m: \x1b[31m./minirt *.rt");
	minirt = get_file_data(argv[1]);
	init_mlx(&minirt);
	raytrace(&minirt);
	draw_window(&minirt);
	destroy_mlx(&minirt);
	free_all(&minirt);
	return (0);
}