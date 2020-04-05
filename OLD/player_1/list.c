/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 22:38:34 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 20:42:16 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_ret *ret_init()
{
	t_ret *ret;
	ret = NULL;
	if(!(ret = (t_ret *)malloc(sizeof(t_ret))))
		return(NULL);
	ret->note = 0;
	ret->nb = 0;
	ret->num = 0;
	return (ret);
}

t_list *list_init()
{
	int v;
	v = -1;
	t_list *file;
	file = NULL;
	if(!(file = (t_list *)malloc(sizeof(t_list) + (8 * sizeof(t_coord)))))
		return(NULL);
	while(++v < 8)
	{
		file->vertex[v] = *init_coord();
		file->vertex[v].sommet = NULL;
	}
	file->point_list = init_coord();
	file->player = 0;
	file->nb_adj = 0;
	file->step = 0;
	file->nb_player = 0;
	file->pre = NULL;
	file->visit_1 = -2;/*-1 jms visiter 0 creer 1 adjacenter*/
	file->visit_2 = -2;/*-1 jms visiter 0 creer 1 adjacenter*/
	file->visit_3 = -2;/*-1 jms visiter 0 creer 1 adjacenter*/
	file->visit_4 = -2;/*-1 jms visiter 0 creer 1 adjacenter*/
	file->data = 0;
	file->pose_x = 0;
	file->pose_y = 0;
	return (file);
}
t_list *attach(t_list *init, t_list *sommet)
{
	if(!init || !sommet)
		return(NULL);
	init->pre = sommet;
	return(init);
}
t_coord *init_coord()
{
	t_coord *point;
	point = NULL;
	if(!(point = (t_coord *)malloc(sizeof(t_coord))))
		return(NULL);
	point->x = 0;
	point->y = 0;
	return (point);
}
t_pile *pile_init()
{
	t_pile *pile;
	pile = NULL;
	if(!(pile = (t_pile *)malloc(sizeof(t_pile) +(7 * sizeof(t_coord)) +sizeof(t_list))))
			return(NULL);
	pile->sommet = NULL;
	pile->pre = NULL;
	pile->sv = NULL;
	pile->x = 0;
	pile->y = 0;
	return (pile);
}
t_map *map_init()
{
	t_map *map;
	map = NULL;
	if(!(map = (t_map *)malloc(sizeof(t_map))))
		return(NULL);
	map->hight = 0;
	map->weight = 0;
	return (map);
}

