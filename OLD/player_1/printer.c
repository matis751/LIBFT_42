#include "list.h"

void printer(t_list *sommet, t_map *map, t_pile *pile)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while(y < map->hight)
	{
		while(x < map->weight)
		{
			befor(&pile);
			if(pile)
			while(pile->x != x || pile->y != y)
			{
				pile_sv(&pile);
				if(!pile)
					break;
			}
			if(pile)
				write(1, &pile->sommet->data, 1);
			x++;
		}
		write(1, "\n", 1);
		x = 0;
		y++;
	}
	write(1, "\n", 1);
}
