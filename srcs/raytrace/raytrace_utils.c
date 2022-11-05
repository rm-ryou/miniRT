#include "raytrace.h"

static double	trim_0_1(double num)
{
	if (num >= 1)
		return (1);
	else if (num <= 0)
		return (0);
	return (num);
}

t_color	add_dif_ref_info(t_minirt_data *minirt, t_inter_point *point_of_object)
{
	t_color		out_put_color;
	t_vector	light_dir;
	t_vector	reverse_eye_dir;
	t_vector	ref_dir;
	double		dot_norm_light;

	out_put_color = new_color(0, 0, 0);
	light_dir = normalize_vec(sub_vec(minirt->light->point, point_of_object->position));
	dot_norm_light = trim_0_1(dot_vec(point_of_object->norm_vec, light_dir));
	out_put_color = add_color(out_put_color, 0.64 * minirt->light->range * dot_norm_light);//(minirt->light->range * dot_norm_light * 1000) / (4 * M_PI));//
	if (dot_norm_light)
	{
		ref_dir = sub_vec(mult_vec(point_of_object->norm_vec, 2 * dot_norm_light), light_dir);
		reverse_eye_dir = normalize_vec(mult_vec(minirt->ray->direction, -1));
		dot_norm_light = trim_0_1(dot_vec(ref_dir, reverse_eye_dir));
		out_put_color = add_color(out_put_color, 0.42 * minirt->light->range * pow(dot_norm_light, 8));
	}
	return (out_put_color);
}

static int	intersection(t_object *object, t_ray *ray, t_inter_point *inter_point)
{
	if (object->type == SPHERE)
		return (solve_sphere(ray, &object->object.sphere, inter_point));
	else if (object->type == PLANE)
		return (solve_plane(ray, &object->object.plane, inter_point));
	else if (object->type == CYLINDER)
		return (solve_cylinder(ray, &object->object.cylinder, inter_point));
	return (0);
}

int	get_nearest_object(t_minirt_data *minirt, t_ray *ray, t_inter_point *point_of_object)
{
	int				res;
	t_object		*cur_object;

	res = 0;
	cur_object = minirt->objects;
	point_of_object->distance = INT_MAX;
	while (cur_object)
	{
		res += intersection(cur_object, ray, point_of_object);
		cur_object = cur_object->next;
	}
	return (res);
}
