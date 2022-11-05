#include "raytrace.h"

int	get_shadow_ray(t_minirt_data *minirt, t_inter_point *point_of_object)
{
	t_ray	shadow_ray;

	shadow_ray.start = add_vec(point_of_object->position, mult_vec(point_of_object->norm_vec, (double)1 / 128));
	shadow_ray.direction = normalize_vec(sub_vec(minirt->light->point, point_of_object->position));
	return (get_nearest_object(minirt, &shadow_ray, point_of_object));
}

t_color	launch_raytracing(t_minirt_data *minirt)
{
	t_inter_point	point_of_object;
	t_color			out_put_color;

	out_put_color = new_color(0, 0, 0);
	if (get_nearest_object(minirt, minirt->ray, &point_of_object))
	{
		out_put_color = add_color(out_put_color, 0.01 * minirt->ambient->range);
		if (get_shadow_ray(minirt, &point_of_object))
			return (out_put_color);
		out_put_color = add_color2color(out_put_color, add_dif_ref_info(minirt, &point_of_object));
		out_put_color = multi_color2color(out_put_color, point_of_object.object_color);
	}
	return (out_put_color);
}

static void	set_ray(t_minirt_data *minirt, double x, double y)
{
	t_vector	w_point;

	x = x - (W_DISPLAY - 1) / 2;
	y = (H_DISPLAY - 1) / 2 - y;
	w_point = add_vec(mult_vec(minirt->screen->x, x), mult_vec(minirt->screen->y, y));
	minirt->ray->direction = normalize_vec(add_vec(minirt->screen->center, w_point));
	minirt->ray->start = minirt->camera->view_point;
}

void	raytrace(t_minirt_data *minirt)
{
	double	x;
	double	y;
	t_color	out_put_color;

	x = 0;
	while (x < W_DISPLAY)
	{
		y = 0;
		while (y < H_DISPLAY)
		{
			out_put_color = new_color(1, 1, 1);
			set_ray(minirt, x, y);
			out_put_color = launch_raytracing(minirt);
			my_mlx_pixel_put(minirt->img, x, y, create_trgb(&out_put_color));
			y++;
		}
		x++;
	}
}
