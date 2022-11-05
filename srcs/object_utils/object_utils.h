#ifndef OBJECT_UTILS_H
# define OBJECT_UTILS_H

# include "minirt_struct.h"
# include "utils.h"

void		insert_last_node_object(t_object **object, t_object *new_object);
t_object	*create_new_object(e_object_type object_type);

#endif /* OBJECT_UTILS_H */