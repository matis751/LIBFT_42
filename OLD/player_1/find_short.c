#include "list.h"
/*void rec_path(t_list *sommet, t_path *path)
{
	static int c;
	int v;
	v = 0;

	while(v <= sommet->nb_adj)
	{
		if(sommet->vertex[v].sommet)
		{
			path->nb = c++;
			if(sommet->player == 2)
			{
				path->point = sommet->point_list;
				break;
			}
			path->point = sommet->point_list;
			path_init_sv(&path);
			rec_path(sommet->vertex[v].sommet, path);
		}
		v++;
	}

}
*/

void find_short(t_list *sommet, t_pile *pile)
{
	t_path *path;
	path = path_init();
	path->point = sommet->point_list;
/*	rec_path(sommet, path);*/
	while(path->sv)
		path_sv(&path);
}
