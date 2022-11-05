#include "utils.h"

void	free_all(t_minirt_data *minirt)
{
	t_object	*for_free;

	free(minirt->img);
	free(minirt->ambient);
	free(minirt->camera);
	free(minirt->light);
	while (minirt->objects)
	{
		for_free = minirt->objects;
		minirt->objects = minirt->objects->next;
		free(for_free);
	}
	free(minirt->objects);
	free(minirt->screen);
	free(minirt->ray);
}