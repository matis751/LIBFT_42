
#include "includes/filler.h"
#include "includes/graph.h"
#include "includes/list.h"

void graph_init(t_list *file, char *debut)
{
	int x;
	int y;

	x = 0;
	y = 0;
	t_list *tmp;
	tmp = file;
	while(*debut)
	{
		file->data = (void *)debut;
		file->visit = 0;
		set_coord(file, x, y);
		*debut != '\n' ? is_vertex(file) : new_line(&x, &y);
		list_chaine(&file);
		debut++;
		x++;
	}
	file = tmp;
	adr_vertex(file);
}

int bfs(char *buff)
{
	t_list *file;
	char *debut;
	debut = buff;
	file = list_init();
	graph_init(file, debut);
	return (0);
}
