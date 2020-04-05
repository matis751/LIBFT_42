#include "filler.h"

int player_parser(t_filler **tmp_filler, t_map *map)
{
	t_filler *filler = NULL;
	int ret = 0;
	char *tmp = NULL;
	

	filler = *tmp_filler;
	if((tmp = ft_strstr("$$$ exec p1 : [mel-oual.filler]", map->buff)))
		filler->player_nb = ft_atoi(tmp + 10);
	if((tmp = ft_strstr("$$$ exec p2 : [mel-oual.filler]", map->buff)))
		filler->player_nb = ft_atoi(tmp + 10);
	if (filler->player_nb != 1 && filler->player_nb != 2)
	{
		ret = -1;
		print_input_error(1);
	}
	filler->state = 1;
	return (ret);
}
