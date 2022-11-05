#ifndef PARSER_H
#define PARSER_H

# include "object_utils.h"
# include "get_next_line.h"
# include "libft.h"
# include "math_utils.h"
# include "utils.h"

t_color			check_color(char *colors_str);
double			check_light_range(char *str_double);
t_vector		check_norm_vector_range(char *norm_points);
int				get_args_size(char **args);
t_minirt_data	get_file_data(char *filepath);
t_vector		get_vector(char *vector_str);
void			set_ambient(t_minirt_data *minirt, char *line);
void			set_camera(t_minirt_data *minirt, char *line);
void			set_light(t_minirt_data *minirt, char *line);
void			set_list(char *filepath, t_list **value_list);
void			set_sphere(t_object **object, char *line);
void			set_plane(t_object **object, char *line);
void			set_cylinder(t_object **object, char *line);

#endif /* PARSER_H */