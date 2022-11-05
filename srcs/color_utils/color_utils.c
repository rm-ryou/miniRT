#include "color_utils.h"

t_color	new_color(double red, double green, double blue)
{
	t_color	new;

	new.red = red;
	new.green = green;
	new.blue = blue;
	return (new);
}

int		create_trgb(t_color *color)
{
	return ((int)color->red << 16 | (int)color->green << 8 | (int)color->blue);
}
