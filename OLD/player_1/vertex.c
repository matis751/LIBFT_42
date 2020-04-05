/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:00:13 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/25 18:49:19 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void find_vertex(t_list *sommet, t_map *map, t_pile *pile) /*recherche des sommets vertex*/
{
	int x = -1;
	int y = -1;
	int v = -1;
	static int c = -1;
	if(!sommet|| !map || !pile)
		return;
	while(y < 2)
	{
		if(sommet->point_list->y + y < map->hight && sommet->point_list->y + y >= 0)
		{
			while(x < 2)
			{
				if(sommet->point_list->x + x < map->weight && sommet->point_list-> x + x >= 0) /*si x et y est dans la map*/
				{
					sommet->nb_adj++;
					v++;
					set_coord(sommet, pile, x, y, v);
					if(!compar_point(&pile, &sommet->vertex[v]))
					{
						set_vertex(sommet, x, y, v);
						set_pile(pile, sommet, x, y, v);
					}
					else
						if(pile->sommet)
							if(!list_coord(pile->sommet, sommet))
							{
								sommet->vertex[v].sommet = pile->sommet;
								befor(&pile);
							}
				}
				x++;
			}
		}
	y++;
	x = -1;
	}
	sommet->visit_1 = 1; /*car out les vertex on ete visiter*/
	v = -1;
/*	printf("SOMMET_NUMERO_%d ADR '%p' x = %d et y = %d\n%p x = %d, y = %d, %p x = %d, y = %d, %p x = %d, y = %d, %p x = %d, y = %d, %p x = %d, y = %d, %p x = %d, y = %d, %p x = %d, y = %d, %p x = %d, y = %d\n\n",++c ,sommet, sommet->point_list->x, sommet->point_list->y, sommet->vertex[0].sommet, sommet->vertex[0].x, sommet->vertex[0].y, sommet->vertex[1].sommet, sommet->vertex[1].x, sommet->vertex[1].y, sommet->vertex[2].sommet, sommet->vertex[2].x, sommet->vertex[2].y, sommet->vertex[3].sommet, sommet->vertex[3].x, sommet->vertex[3].y, sommet->vertex[4].sommet, sommet->vertex[4].x, sommet->vertex[4].y, sommet->vertex[5].sommet, sommet->vertex[5].x, sommet->vertex[5].y, sommet->vertex[6].sommet, sommet->vertex[6].x, sommet->vertex[6].y, sommet->vertex[7].sommet, sommet->vertex[7].x, sommet->vertex[7].y);*/
	while(++v <=  sommet->nb_adj)
		(sommet->vertex[v].sommet != NULL && sommet->vertex[v].sommet->visit_1 != 1) ? find_vertex(sommet->vertex[v].sommet, map, pile) : NULL;
}

