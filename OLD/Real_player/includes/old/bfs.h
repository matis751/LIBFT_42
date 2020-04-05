#include "graph.h"
#include "list.h"
#include "filler.h"

/*****************************************************************************
* *
* Define a structure for vertices in a breadth-first search. *
* *
*****************************************************************************/
typedef struct BfsVertex_ {
void *data;
VertexColor color;
int hops;
} BfsVertex;
/*****************************************************************************
* *
* --------------------------- Public Interface --------------------------- *
* *
*****************************************************************************/
int bfs(Graph *graph, BfsVertex *start, List *hops);
#endif
