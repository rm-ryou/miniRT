#ifndef RAYTRACE_H
# define RAYTRACE_H

# include "mlx_utils.h"
# include "minirt.h"

t_color	add_dif_ref_info(t_minirt_data *minirt, t_inter_point *point_of_object);
int		get_nearest_object(t_minirt_data *minirt, t_ray *ray, t_inter_point *point_of_object);
int		solve_cylinder(t_ray *ray, t_cylinder *cylinder, t_inter_point *inter_point);
int		solve_plane(t_ray *ray, t_plane *plane, t_inter_point *inter_point);
int		solve_sphere(t_ray *ray, t_sphere *sphere, t_inter_point *inter_point);


#endif /* RAYTRACE_H */