#ifndef COLOR_UTILS_H
# define COLOR_UTILS_H

typedef struct	s_color
{
	double	red;
	double	green;
	double	blue;
}	t_color;

t_color	new_color(double red, double green, double blue);
int		create_trgb(t_color *color);
t_color	add_color(t_color a, double n);
t_color	add_color2color(t_color a, t_color b);
t_color	multi_color(t_color a, double n);
t_color	multi_color2color(t_color a, t_color b);

#endif /* COLOR_TILS_H */