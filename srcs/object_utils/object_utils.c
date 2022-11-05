#include "object_utils.h"

static t_object	*get_last_object_(t_object *object)
{
	while (object)
	{
		if (!object->next)
			return (object);
		object = object->next;
	}
	return (object);	
}

void	insert_last_node_object(t_object **object, t_object *new_object)
{
	t_object	*tmp;

	if (object)
	{
		if (!*object)
			*object = new_object;
		else
		{
			tmp = get_last_object_(*object);
			tmp->next = new_object;
		}
	}
}

t_object	*create_new_object(e_object_type object_type)
{
	t_object	*new;

	new = (t_object *)x_malloc(sizeof(t_object));
	new->type = object_type;
	new->next = NULL;
	return (new);
}