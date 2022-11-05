#include "parser.h"

void	set_sphere(t_object **object, char *line)
{
	char		**args;
	t_object	*new_object;

	new_object = create_new_object(SPHERE);
	args = ft_split(line, ' ');
	if (get_args_size(args) != 4)
		put_message_exit("The number of sphere arguments is different.");
	new_object->object.sphere.position = get_vector(args[1]);
	new_object->object.sphere.dia = get_double(args[2]);
	new_object->object.sphere.color = check_color(args[3]);
	free_darray(args);
	insert_last_node_object(object, new_object);
}

void	set_plane(t_object **object, char *line)
{
	char		**args;
	t_object	*new_object;

	new_object = create_new_object(PLANE);
	args = ft_split(line, ' ');
	if (get_args_size(args) != 4)
		put_message_exit("The number of plane arguments is different.");
	new_object->object.plane.position = get_vector(args[1]);
	new_object->object.plane.norm_vec = check_norm_vector_range(args[2]);
	new_object->object.plane.color = check_color(args[3]);
	free_darray(args);
	insert_last_node_object(object, new_object);
}

void	set_cylinder(t_object **object, char *line)
{
	char		**args;
	t_object	*new_object;

	new_object = create_new_object(CYLINDER);
	args = ft_split(line, ' ');
	if (get_args_size(args) != 6)
		put_message_exit("The number of cylinder arguments is different.");
	new_object->object.cylinder.position = get_vector(args[1]);
	new_object->object.cylinder.norm_vec = check_norm_vector_range(args[2]);
	new_object->object.cylinder.dia = get_double(args[3]);
	new_object->object.cylinder.height = get_double(args[4]);
	new_object->object.cylinder.color = check_color(args[5]);
	free_darray(args);
	insert_last_node_object(object, new_object);
}
