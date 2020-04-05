#ifndef GRAPH_H
#define GRAPH_H
#include "list.h"
#include "set.h"

/*typedef struct s_graph
{
	int nb_s;
	int nb_v;

	t_list	list_adj;
} t_graph;
*/

typedef enum t_vertex {O, o, X, x} VERTEX;

void graph_init(t_list *file, char *debut);
void contact(char *debut, char *end);
void is_vertex(t_list *file);
#endif
