#include "fillit.h"

/*
 * These functions are to be used when :
 * the file is read char by char : a chained list should be created. To do so,
 * convert_file(1) should be called. (First step once the file descriptor is
 * verified and validated).
 */

 /*
  * Will delete the node given in parameter and will return the one pointed by
  * next.
  */
 static t_filechar	     *switch_to_next(t_filechar **lst)
 {
 	t_filechar	*previous;

 	if (lst && *lst)
 	{
 		previous = *lst;
 		*lst = (*lst)->next;
 		free(previous);
 		previous = NULL;
 	}
 	return (*lst);
 }

static t_filechar		*create_object(char c)
{
	t_filechar		*new_object;

	if (!(new_object = (t_filechar *)malloc(sizeof(t_filechar))))
		return (0);
	new_object->c = c;
	new_object->next = 0;
	return (new_object);
}

t_filechar	             **convert_file(int fd)
{
	t_filechar		**begin_list;
	t_filechar		*current_object;
	char			*buffer;

	if (!((buffer = (char *)malloc(sizeof(char))))
			|| !((begin_list = (t_filechar **)malloc(sizeof(t_filechar *)))))
		return (0);
	current_object = 0;
	while (read(fd, buffer, 1) > 0 && *buffer != EOF)
	{
		if (current_object)
		{
			current_object->next = create_object(*buffer);
			current_object = current_object->next;
		}
		else
		{
			*begin_list = create_object(*buffer);
			current_object = *begin_list;
		}
	}
	return (begin_list);
}
