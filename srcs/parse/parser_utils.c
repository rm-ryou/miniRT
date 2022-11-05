#include "parser.h"

t_vector	get_vector(char *vector_str)
{
	char	**vector_array;
	double	x;
	double	y;
	double	z;

	vector_array = ft_split(vector_str, ',');
	if (get_args_size(vector_array) != 3)
		put_message_exit("The number of arguments for the coordinates is different.");
	x = get_double(vector_array[0]);
	y = get_double(vector_array[1]);
	z = get_double(vector_array[2]);
	free_darray(vector_array);
	return (new_vec(x, y, z));
}

double	check_light_range(char *str_double)
{
	double	num;

	num = get_double(str_double);
	if (num < 0 || num > 1)
		put_message_exit("The range of numbers is different.");
	return (num);
}

t_color	check_color(char *colors_str)
{
	double	red;
	double	green;
	double	blue;
	char	**color_array;
	t_color	color;

	color_array = ft_split(colors_str, ',');
	if (get_args_size(color_array) > 3)
		put_message_exit("Different number of colors.");
	red = ft_atoi(color_array[0]);
	green = ft_atoi(color_array[1]);
	blue = ft_atoi(color_array[2]);
	free_darray(color_array);
	return (new_color(red, green, blue));
}

static int	check_norm(double x, double y, double z)
{
	int	res;

	res = 0;
	if (x < -1 || x > 1)
		res = 1;
	else if (y < -1 || y > 1)
		res = 1;
	else if (z < -1 || z > 1)
		res = 1;
	return (res);
}

t_vector	check_norm_vector_range(char *norm_points)
{
	char	**norm_point;
	double	x;
	double	y;
	double	z;

	norm_point = ft_split(norm_points, ',');
	if (get_args_size(norm_point) != 3)
		put_message_exit("The number of arguments for the coordinates is different.");
	x = get_double(norm_point[0]);
	y = get_double(norm_point[1]);
	z = get_double(norm_point[2]);
	free_darray(norm_point);
	if (check_norm(x, y, z))
		put_message_exit("The range of numbers is different.");
	return (new_vec(x, y, z));
}