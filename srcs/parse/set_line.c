#include "parser.h"

int	get_args_size(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

void	set_ambient(t_minirt_data *minirt, char *line)
{
	char	**args;

	minirt->ambient = (t_ambient *)x_malloc(sizeof(t_ambient));
	args = ft_split(line, ' ');
	if (get_args_size(args) > 3)
		put_message_exit("The number of ambient arguments is different.");
	minirt->ambient->range = check_light_range(args[1]);
	minirt->ambient->color = check_color(args[2]);
	free_darray(args);
}

void	set_camera(t_minirt_data *minirt, char *line)
{
	char	**args;

	minirt->camera = (t_camera *)x_malloc(sizeof(t_camera));
	args = ft_split(line, ' ');
	if (get_args_size(args) > 4)
		put_message_exit("The number of camera arguments is different.");
	minirt->camera->view_point = get_vector(args[1]);
	minirt->camera->norm_vec = check_norm_vector_range(args[2]);
	minirt->camera->range = ft_atoi(args[3]);
	free_darray(args);
}

void	set_light(t_minirt_data *minirt, char *line)
{
	char	**args;

	minirt->light = (t_light *)x_malloc(sizeof(t_light));
	args = ft_split(line, ' ');
	if (get_args_size(args) > 3)
		put_message_exit("The number of light arguments is different.");
	minirt->light->point = get_vector(args[1]);
	minirt->light->range = check_light_range(args[2]);
	free_darray(args);
}
