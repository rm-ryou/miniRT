#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

# include "color_utils.h"
# include "math_utils.h"

typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct	s_ambient
{
	double	range;
	t_color	color;
}	t_ambient;

typedef struct	s_camera
{
	t_vector	view_point;
	t_vector	norm_vec;
	double		range;
}	t_camera;

typedef struct	s_light
{
	t_vector	point;
	double		range;
}	t_light;

typedef struct	s_ray
{
	t_vector	start;
	t_vector	direction;
}	t_ray;

typedef struct	s_screen
{
	t_vector	center;
	t_vector	x;
	t_vector	y;
}	t_screen;

typedef struct	s_inter_point
{
	double		distance;
	t_vector	position;
	t_vector	norm_vec;
	t_color		object_color;
}	t_inter_point;

typedef enum
{
	SPHERE,
	PLANE,
	CYLINDER,
}	e_object_type;

typedef struct	s_sphere
{
	t_vector	position;
	double		dia;
	t_color		color;
}	t_sphere;

typedef struct	s_plane
{
	t_vector	position;
	t_vector	norm_vec;
	t_color		color;
}	t_plane;

typedef struct	s_cylinder
{
	t_vector	position;
	t_vector	norm_vec;
	double		dia;
	double		height;
	t_color		color;
}	t_cylinder;

typedef union s_object_type
{
	t_sphere	sphere;
	t_plane		plane;
	t_cylinder	cylinder;
}	u_object_type;

typedef struct	s_object t_object;
typedef struct	s_object
{
	e_object_type	type;
	u_object_type	object;
	t_object		*next;
}	t_object;

typedef struct	s_minirt_data
{
	void		*mlx;
	void		*mlx_win;
	t_img		*img;
	t_ambient	*ambient;
	t_camera	*camera;
	t_light		*light;
	t_object	*objects;
	t_screen	*screen;
	t_ray		*ray;
}	t_minirt_data;

#endif /* MINIRT_STRUCT_H */