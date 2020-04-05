#include "filler.h"

void *filler_init(t_filler **filler)
{
	t_filler *tmp = NULL;
	tmp = (t_filler *)malloc(sizeof(*tmp));
	tmp->state = 0;
	tmp->player_nb = 0;
	*filler = tmp;
	return((void *)filler);
}

void *map_init(t_map **map)
{
	t_map *tmp = NULL;

	if(!(tmp = (t_map *)malloc(sizeof(*tmp))))
		return(NULL);
	tmp->buff = NULL;
	tmp->size_x = 0;
	tmp->size_y = 0;
	tmp->player_nb = 0;
    tmp->state = 0;
    tmp->piece_x = 0;
    tmp->piece_y = 0;
    tmp->piece_buff = NULL;
	*map = tmp;
	return((void *) *map);
}

void *piece_init(t_piece **piece)
{
	t_piece *tmp = NULL;
	if(!(tmp = (t_piece *)malloc(sizeof(*tmp))))
		return(NULL);
	tmp->line = 0;
	tmp->row = 0;

	*piece = tmp;
	return((void *)*piece);
}
