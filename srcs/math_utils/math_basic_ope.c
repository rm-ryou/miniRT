#include "math_utils.h"

t_vector	add_vec(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x + b.x;
	new.y = a.y + b.y;
	new.z = a.z + b.z;
	return (new);
}

t_vector	sub_vec(t_vector a, t_vector b)
{
	t_vector	new;

	new.x = a.x - b.x;
	new.y = a.y - b.y;
	new.z = a.z - b.z;
	return (new);
}

t_vector	mult_vec(t_vector a, double n)
{
	t_vector	new;

	new.x = a.x * n;
	new.y = a.y * n;
	new.z = a.z * n;
	return (new);
}

double		dot_vec(t_vector a, t_vector b)
{
	double	res;

	res = 0;
	res += a.x * b.x;
	res += a.y * b.y;
	res += a.z * b.z;
	return (res);
}

t_vector	cross_vec(t_vector a, t_vector b)
{
	t_vector	res;

	res.x = a.y * b.z - a.z * b.y;
	res.y = a.z * b.x - a.x * b.z;
	res.z = a.x * b.y - a.y * b.x;
	return (res);
}
