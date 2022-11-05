#include "parser.h"

void	check_filepath(char *filepath)
{
	size_t	path_len;
	int		extension;
	int		flg;

	path_len = ft_strlen(filepath);
	extension = path_len - 3;
	if (extension <= 0)
		put_message_exit("filepath is wrong.");
	flg = ft_strncmp(filepath + extension, ".rt", 3);
	if (flg)
		put_message_exit("filepath is wrong.");
}

void	set_contents(t_list *value_list, t_minirt_data *minirt)
{
	char			*line;

	minirt->objects = NULL;
	while (value_list)
	{
		line = value_list->content;
		if (ft_strchr(line, 'A'))
			set_ambient(minirt, line);
		else if (ft_strchr(line, 'C'))
			set_camera(minirt, line);
		else if (ft_strchr(line, 'L'))
			set_light(minirt, line);
		else if (ft_strnstr(line, "sp", ft_strlen(line)))
			set_sphere(&minirt->objects, line);
		else if (ft_strnstr(line, "pl", ft_strlen(line)))
			set_plane(&minirt->objects, line);
		else if (ft_strnstr(line, "cy", ft_strlen(line)))
			set_cylinder(&minirt->objects, line);
		else
			put_message_exit("invalid contents.");
		value_list = value_list->next;
	}
}

void	set_camera2world_coord(t_screen *screen, t_camera *camera)
{
	screen->x.x = screen->center.z / sqrt(screen->center.z * screen->center.z + screen->center.x * screen->center.x);
	screen->x.y = 0;
	screen->x.z = -screen->center.x / sqrt(screen->center.z * screen->center.z + screen->center.x * screen->center.x);
	screen->y = normalize_vec(cross_vec(screen->x, mult_vec(screen->center, -1)));
	if (camera->norm_vec.x == 0 && camera->norm_vec.y != 0 && camera->norm_vec.z == 0)
	{
		if (camera->norm_vec.y > 0)
		{
			screen->x = new_vec(-1, 0, 0);
			screen->y = new_vec(0, 0, -1);
		}
		else
		{
			screen->x = new_vec(1, 0, 0);
			screen->y = new_vec(0, 0, 1);
		}
	}
}

void	set_info(t_minirt_data *minirt)
{
	double	distance2world_coord;
	double	theta;
	double	height;

	minirt->ray = (t_ray *)x_malloc(sizeof(t_ray));
	minirt->screen = (t_screen *)x_malloc(sizeof(t_screen));
	minirt->img = (t_img *)x_malloc(sizeof(t_img));
	theta = (M_PI / 180) * minirt->camera->range;
	height = tan(theta / 2);
	distance2world_coord = W_DISPLAY / (2 * height);
	minirt->screen->center = mult_vec(minirt->camera->norm_vec, distance2world_coord);
	set_camera2world_coord(minirt->screen, minirt->camera);
}

t_minirt_data	get_file_data(char *filepath)
{
	t_minirt_data minirt;
	t_list	*value_list;

	value_list = NULL;
	check_filepath(filepath);
	set_list(filepath, &value_list);
	set_contents(value_list, &minirt);
	ft_lstclear(&value_list, free);
	set_info(&minirt);
	return (minirt);
}