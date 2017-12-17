#include "fillit.h"

/*
 * This file groups functions that do not belong to any other file.
 */

t_ref   **create_ref(void)
{
    t_ref   **new_ref;

    if (!(new_ref = (t_ref**)malloc(sizeof(t_ref*))) ||
        !(*new_ref = (t_ref*)malloc(sizeof(t_ref))))
        return (NULL);
    (*new_ref)->square_size = MAX_GRID_PAR;
    (*new_ref)->height = MAX_GRID_PAR;
    (*new_ref)->width = MAX_GRID_PAR;
    (*new_ref)->empty_points = MAX_GRID_PAR * MAX_GRID_PAR;
    (*new_ref)->order = NULL;
    return (new_ref);
}
