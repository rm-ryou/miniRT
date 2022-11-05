#include "raytrace.h"

int	solve_plane(t_ray *ray, t_plane *plane, t_inter_point *inter_point)
{
	double	dot;
	double	distance;

	dot = dot_vec(ray->direction, plane->norm_vec);
	if (dot)
	{
		distance = dot_vec(sub_vec(plane->position, ray->start), plane->norm_vec) / dot;
		if (inter_point->distance > distance && distance > (double)1 / 128)
		{
			inter_point->distance = distance;
			inter_point->position = add_vec(ray->start, mult_vec(ray->direction, distance));
			if (dot_vec(ray->direction, plane->norm_vec) > 0)
				plane->norm_vec = mult_vec(plane->norm_vec, -1);
			inter_point->norm_vec = plane->norm_vec;
			inter_point->object_color = plane->color;
			return (1);
		}
	}
	return (0);
}
