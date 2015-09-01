
#ifndef GROUP_H
# define GROUP_H

# include "object.h"
# include "ftlst.h"

typedef struct	s_group
{
	char		*name;
	t_lst		*objects;
}				t_group;

t_group			*group(const char *name);
void			group_add(t_group *group, t_object *object);
void			group_remove(t_group *group, t_object *object);

#endif