#ifndef BFS_H
#define BFS_H

#include "graph.h"

typedef struct s_bfs
{
	void *data;
	VERTEX sign;
	int hops;

} t_bfs;
int bfs(t_graph *graph,  t_bfs *start, t_list *hops);
#endif
