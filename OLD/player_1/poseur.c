/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poseur.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 15:44:32 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 17:33:28 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_list *checking(t_pile *pile, int x, int y)
{
	int ret;
	befor(&pile);
	while(!coord_pile(pile, x, y))
	{
		if(pile->sv)
			pile_sv(&pile);
		else
			break;
	}
	return(pile->sommet);
}
int limit_coord(int x, int y, t_map *map)
{
	if (x >= 0 && x <= map->weight)
		if (y >= 0 && y <= map->hight)
			return (1);
	return(0);
}

void deltat(t_piece *piece, t_list *sommet, int *x, int *y)
{
	int delta_x = 0;
	int delta_y = 0;
	*x = sommet->point_list->x - piece->point->x;
	*y = sommet->point_list->y - piece->point->y;
}
int coord(t_list *sommet, t_piece *piece)
{
	if(sommet->point_list->x == piece->point->x)
		if(sommet->point_list->y == piece->point->y)
			return(1);
	return(0);
}
int one_of(t_list *sommet, t_piece *piece, int x, int y)
{
	while(piece->pre)
		piece_pre(&piece);
	if(sommet->point_list->x == piece->point->x + x)
		if(sommet->point_list->y == piece->point->y + y)
			return(1);
	while(piece->sv)
	{
		if(sommet->point_list->x == piece->point->x + x)
			if(sommet->point_list->y == piece->point->y + y)
				return(1);
		piece_sv(&piece);
	}
	if(sommet->point_list->x == piece->point->x + x)
		if(sommet->point_list->y == piece->point->y + y)
			return(1);
	return(0);
}
int test_pose(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map)
{
	int ret;
	ret = 0;
	int x = 0;
	int y = 0;
	int nb = 0;
	static t_list *tmp = NULL;
	int piece_x;
	int piece_y;
	int tmp_x;

	deltat(piece, sommet, &piece_x, &piece_y);
	piece_x -= piece->max_x;
	piece_y -= piece->max_y;
	tmp_x = piece_x;
	while(y <= piece->max_y)
	{
		while(x <= piece->max_x)
		{
			nb = 0;
			while(piece->num <= piece->nb_p)
			{
				if(!one_of(sommet, piece, piece_x, piece_y))
					break;
				if((!limit_coord(piece->point->x + piece_x, piece->point->y + piece_y, map)) || ((!(tmp = checking(pile, piece->point->x + piece_x, piece->point->y + piece_y)))))
				{
					if(!tmp)
						break;
					if((tmp->data != '.') && !coord(sommet, piece))/*att x*/
						break;
				}
				nb += nb_ennemi(tmp, 1);
				if(piece->num == piece->nb_p)
				{
					if(ret < nb)
					{
						while(piece->pre)
							piece_pre(&piece);
						ret = nb;
						sommet->pose_x = piece->point->x + piece_x;
						sommet->pose_y = piece->point->y + piece_y;
					}
					break;
				}
				piece_sv(&piece);
			}
			x++;
			piece_x++;
			while(piece->pre)
				piece_pre(&piece);
		}
		x = 0;
		piece_x = tmp_x;
		piece_y++;
		y++;
		while(piece->pre)
			piece_pre(&piece);
	}
	return(ret);
}

int test_pose_2(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map)
{
	static t_list *tmp;
	int piece_x;
	int piece_y;

	deltat(piece, sommet, &piece_x, &piece_y);
	while(piece->num <= piece->nb_p)
	{
		if((!limit_coord(piece->point->x + piece_x, piece->point->y + piece_y, map)) || ((!(tmp = checking(pile, piece->point->x + piece_x, piece->point->y + piece_y)) || (tmp->data != '.' && piece->num != 1))))
			return(0);
		if(piece->num == piece->nb_p)
			break;
		piece_sv(&piece);
	}
	return (1);
}
t_list *poseur(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map, int nb)
{
	int x;
	static int ret = 0;
	static t_list *vr = NULL;
	int tmp = 0;
	x = -1;

	sommet->visit_4 = nb;
	if(sommet->player == map->p)
	{
		if((tmp = test_pose(sommet, piece, pile, map)) > ret)
			{
				ret = tmp;
				vr = sommet;
			}
	}
	while(++x < sommet->nb_adj)
		if(sommet->vertex[x].sommet && sommet->vertex[x].sommet->visit_4 != nb)
			poseur(sommet->vertex[x].sommet, piece, pile, map, nb);
	return(vr ? vr : find_closest(checking(pile, 0, 0), &vr, piece, pile, map));
}
