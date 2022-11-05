#include "raytrace.h"

static int	set_inter_point_minus(t_inter_point *inter_point, t_cylinder *cylinder, double height, double distance, t_vector inter_cy)
{
	t_vector	center2p;

	center2p = sub_vec(inter_cy, cylinder->position);
	inter_point->norm_vec = normalize_vec(sub_vec(center2p, mult_vec(cylinder->norm_vec, height)));
	inter_point->distance = distance;
	inter_point->position = inter_cy;
	return (1);
}

static int	set_inter_point_plus(t_inter_point *inter_point, t_cylinder *cylinder, double height, double distance, t_vector inter_cy)
{
	t_vector	center2p;

	center2p = sub_vec(inter_cy, cylinder->position);
	inter_point->norm_vec = normalize_vec(sub_vec(mult_vec(cylinder->norm_vec, height), center2p));
	inter_point->distance = distance;
	inter_point->position = inter_cy;
	return (1);
}

int	conditional_expre_cylinder(t_ray *ray, t_cylinder *cylinder, t_inter_point *inter_point, double minus_dis, double plus_dis)
{
	t_vector	inter_plus;
	t_vector	inter_minus;
	double		height_plus;
	double		height_minus;

	inter_minus = add_vec(ray->start, mult_vec(ray->direction, minus_dis));
	inter_plus = add_vec(ray->start, mult_vec(ray->direction, plus_dis));
	height_minus = dot_vec(sub_vec(inter_minus, cylinder->position), cylinder->norm_vec);
	height_plus = dot_vec(sub_vec(inter_plus, cylinder->position), cylinder->norm_vec);
	inter_point->object_color = cylinder->color;
	if (inter_point->distance > minus_dis && minus_dis > (double)1 /  128 && height_minus >= 0 && height_minus <= cylinder->height)
		return (set_inter_point_minus(inter_point, cylinder, height_minus, minus_dis, inter_minus));
	else if (inter_point->distance > plus_dis && plus_dis > (double)1 / 128 && height_plus >= 0 && height_plus <= cylinder->height)
		return (set_inter_point_plus(inter_point, cylinder, height_plus, plus_dis, inter_plus));
	return (0);
}

int	solve_cylinder(t_ray *ray, t_cylinder *cylinder, t_inter_point *inter_point)
{
	double	A;
	double	B;
	double	C;
	double	D;
	
	A = mag_vec(cross_vec(ray->direction, cylinder->norm_vec));
	A = pow(A, 2);
	B = 2 * dot_vec(cross_vec(ray->direction, cylinder->norm_vec), cross_vec(sub_vec(ray->start, cylinder->position), cylinder->norm_vec));
	C = mag_vec(cross_vec(sub_vec(ray->start, cylinder->position), cylinder->norm_vec));
	C = pow(C, 2) - pow(cylinder->dia, 2);
	D = pow(B, 2) - 4 * A * C;
	if (D >= 0)
		return (conditional_expre_cylinder(ray, cylinder, inter_point, (-B - sqrt(D)) / (2 * A), (-B + sqrt(D)) / (2 * A)));
	return (0);
}
