#include "math_utils.h"

t_vector	new_vec(double x, double y, double z)
{
	t_vector	new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

double		mag_vec(t_vector a)
{
	double	res;

	res = 0;
	res += pow(a.x, 2);
	res += pow(a.y, 2);
	res += pow(a.z, 2);
	return (sqrt(res));
}

double		mag_sqrt_vec(t_vector a)
{
	double	res;

	res = 0;
	res += pow(a.x, 2);
	res += pow(a.y, 2);
	res += pow(a.z, 2);
	return (res);
}

t_vector	normalize_vec(t_vector a)
{
	double		norm;
	t_vector	new;

	norm = mag_vec(a);
	new.x = a.x / norm;
	new.y = a.y / norm;
	new.z = a.z / norm;
	return (new);
}
