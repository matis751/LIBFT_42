#include "filler.h"

int main(void)
{
	t_map *map = NULL;

    if(!(map_init(&map)))
		return(-1);
	while(1)
	{
		if(!(reader(map)))
			return(-1);
        break;
	}
}
