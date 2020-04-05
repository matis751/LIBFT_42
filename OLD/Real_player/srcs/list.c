#include "../includes/list.h"
#include "../includes/filler.h"

t_list *list_init()/*initialise list*/
{
	t_list *list;
	list = (t_list *)malloc(sizeof(t_list));
	list->vertex = (t_vertex *)malloc(sizeof(t_vertex));
	list->point_list = (t_coord *)malloc(sizeof(t_coord));
	ft_bzero(list->vertex->adj, sizeof(list->vertex->adj));
	list->point_list->x = 0;
	list->point_list->y = 0;
	list->visit = 0;
	list->befor = NULL;
	list->next = NULL;
	return (list);
}
void list_chaine(t_list **file)/*renvoie une liste rattacher a c'elle envoyer*/
{
	t_list *list;
	t_list *tmp;
	list = *file;
	tmp = list_init();
	list->next = tmp;
	tmp->befor = (t_list *)malloc(sizeof(t_list));
	tmp->befor = list;
	list = list->next;
	*file = list;
}

void remote_list(t_list **list)/*remonte la list*/
{
	t_list *tmp;
	tmp = *list;
	tmp->next = tmp;
	tmp = tmp->befor;
	*list = tmp;
}
