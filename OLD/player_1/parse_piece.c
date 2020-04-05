#include "list.h"
int nb_point(char *piece)
{
	int ret;
	int x;
	x = -1;
	ret = 0;
	while(piece[++x])
		if(piece[x] == '*')
			ret++;
	return (ret);
}
void parse_piece(char *piece, t_piece *struct_piece)
{
	int x;
	int y;
	int v;
	int nb = 0;;
	int d_x;
	int d_y;
	int num;
	int ret;
	t_piece *tmp;
	tmp = struct_piece;

	x = -1;
	v = -1;
	ret = 0;
	y = 0;
	num = 0;
	d_x = 0;/*touver moyen conaitre max x et y pour plaer pieces*/
	d_y = 1;

	while(piece[++v])
	{
		++x;
		if(piece[v] == '*')
		{
			struct_piece->num = ++num;
			struct_piece->point->x = x;
			struct_piece->point->y = y;
			struct_piece->sv = piece_init();
			struct_piece->nb_p = nb_point(piece);
			piece_sv(&struct_piece);
			d_x++;
		}
		if(piece[v] == '\n')
		{
			if(d_x > ret)
				ret = d_x;
			if(d_x)
				y++;
			d_x = 0;
			d_y++;
			x = -1;
		}

	}
	while(tmp->nb_p >= tmp->num)
	{
		tmp->max_x = ret;
		tmp->max_y = y;
		if(tmp->sv)
			piece_sv(&tmp);
		if(tmp->nb_p == tmp->num)
			break;
	}
}
