#include "list.h"

t_path *path_init()
{
	t_path *path;
	path = (t_path *)malloc(sizeof(t_path));
	path->pre = NULL;
	path->nb = 0;
	path->point = init_coord();
	path->sv = NULL;
	return(path);
}
void path_init_sv(t_path **path)
{
	t_path *tmp;
	t_path *tmp_2;

	tmp = *path;
	tmp_2 = *path;
	tmp->sv = path_init();
	tmp = tmp->sv;
	tmp->pre = tmp_2;
	*path = tmp;
}

void path_sv(t_path **path)
{
	t_path *tmp;
	t_path *tmp_2;

	tmp = *path;
	tmp_2 = *path;
	tmp = tmp->sv;
	tmp->pre = tmp_2;
	*path = tmp;
	
}
