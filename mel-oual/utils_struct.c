#include "filler.h"

void *init_map(t_map **map)
{
	t_map *tmp = NULL;
	if(!(tmp = (t_map *)malloc(sizeof(t_map))))
		return(NULL);
	tmp->size_x = 0;
	tmp->size_y = 0;
    tmp->piece_x = 0;
    tmp->piece_y = 0;
	tmp->player_nb = 0;
    tmp->piece_buff = NULL;
    tmp->buff = NULL;
	return((void *)(*map = tmp));
}
