#include "color_utils.h"

t_color	add_color(t_color a, double n)
{
	t_color	new;

	new.red = a.red + n;
	new.green = a.green + n;
	new.blue = a.blue + n;
	return (new);
}

t_color	add_color2color(t_color a, t_color b)
{
	t_color	new;

	new.red = a.red + b.red;
	new.green = a.green + b.green;
	new.blue = a.blue + b.blue;
	return (new);
}

t_color	multi_color(t_color a, double n)
{
	t_color	new;

	new.red = a.red * n;
	new.green = a.green * n;
	new.blue = a.blue * n;
	return (new);
}

t_color	multi_color2color(t_color a, t_color b)
{
	t_color	new;

	new.red = a.red * b.red;
	new.green = a.green * b.green;
	new.blue = a.blue * b.blue;
	return (new);
}
