#include "raytrace.h"

static double	solove_conditional_expre(double A, double B, double D)
{
	double	plus_ans_of_expre;
	double	minus_ans_of_expre;
	double	res_of_expre;

	plus_ans_of_expre = (-B + sqrt(D)) / (2 * A);
	minus_ans_of_expre = (-B - sqrt(D)) / (2 * A);
	if (plus_ans_of_expre > 0 && minus_ans_of_expre > 0)
	{
		if (plus_ans_of_expre < minus_ans_of_expre)
			res_of_expre = plus_ans_of_expre;
		else
			res_of_expre = minus_ans_of_expre;
	}
	else
	{
		if (plus_ans_of_expre > minus_ans_of_expre)
			res_of_expre = plus_ans_of_expre;
		else
			res_of_expre = minus_ans_of_expre;
	}
	return (res_of_expre);
}

static double	conditional_expre_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vector	point_of_ray_sphere;
	double		A;
	double		B;
	double		C;
	double		D;

	point_of_ray_sphere = sub_vec(ray->start, sphere->position);
	A = dot_vec(ray->direction, ray->direction);
	B = 2 * dot_vec(ray->direction, point_of_ray_sphere);
	C = dot_vec(point_of_ray_sphere, point_of_ray_sphere) - pow(sphere->dia, 2);
	D = pow(B, 2) - 4 * A * C;
	if (D == 0)
		return (-B / (2 * A));
	else if (D > 0)
		return (solove_conditional_expre(A, B, D));
	else
		return (-1);
}

int	solve_sphere(t_ray *ray, t_sphere *sphere, t_inter_point *inter_point)
{
	t_vector	point_of_ray_sphere;
	double		distance;

	distance = conditional_expre_sphere(ray, sphere);
	if (inter_point->distance > distance && distance > 0)
	{
		inter_point->distance = distance;
		inter_point->position = add_vec(ray->start, mult_vec(ray->direction, distance));
		inter_point->norm_vec = normalize_vec(sub_vec(inter_point->position, sphere->position));
		inter_point->object_color = sphere->color;
		return (1);
	}
	return (0);
}
