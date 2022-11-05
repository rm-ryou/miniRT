#ifndef MATH_UTILS_H
# define MATH_UTILS_H

# include <math.h>

typedef struct	s_vector
{
	double	x;
	double	y;
	double	z;
}	t_vector;

t_vector	new_vec(double x, double y, double z);
t_vector	add_vec(t_vector a, t_vector b);
t_vector	sub_vec(t_vector a, t_vector b);
t_vector	mult_vec(t_vector a, double n);
double		dot_vec(t_vector a, t_vector b);
t_vector	cross_vec(t_vector a, t_vector b);
double		mag_vec(t_vector a);
double		mag_sqrt_vec(t_vector a);
t_vector	normalize_vec(t_vector a);

#endif // !MATH_UTILS_H