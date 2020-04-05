#ifndef LIST_H
#define LIST_H
typedef struct s_coord
{
	int x;
	int y;
	void *adr;
} t_coord;

typedef struct s_vertex
{
	t_coord adj [8];
	/*void adr_adj [8];*/

} t_vertex;

typedef struct s_list
{
	struct s_list *befor;
	t_coord *point_list;
	int visit;
	void *data;
	t_vertex *vertex;
	struct s_list *next;
} t_list;


t_list *list_init();
void remote_list(t_list **list);
void list_chaine(t_list **list);
#endif
