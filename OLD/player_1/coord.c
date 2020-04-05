/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:39:09 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 19:31:14 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
void befor(t_pile **pile)
{
	t_pile *tmp;
	tmp = NULL;
	if(*pile != NULL)
	{
		tmp = *pile;
		while(tmp->pre)
			pile_pre(&tmp);
		*pile = tmp;
	}
}
void next(t_pile **pile)
{
	t_pile *tmp;
	tmp = NULL;
	tmp = *pile;
	while(tmp->sv)
		pile_sv(&tmp);
	*pile = tmp;
}

int list_coord(t_list *sommet, t_list *sommet_2)
{
	if(sommet == NULL || sommet_2 == NULL)
		return(0);
	return(((sommet->point_list->x == sommet_2->point_list->x) 
				&& (sommet->point_list->y == sommet_2->point_list->y)) ? 1 : 0);
}
int compar_point(t_pile **tmp, t_coord *vertex)
{
	t_pile *pile;
	pile = NULL;
	if(!vertex && !tmp && !*tmp)
		return(0);
	pile = *tmp;
	befor(&pile);
	while (pile)
	{
		if(vertex->x == pile->x && vertex->y == pile->y)
		{ *tmp = pile;
			return(1);
		}
		if (pile->sv)
			pile_sv(&pile);
		else
			break ;/*cmp les coord, return si ok sinn suivant*/
	}
	*tmp = pile;
	return (0);
}

void set_coord(t_list *sommet, t_pile *pile, int x, int y, int v)
{
	if(sommet)
	{
		sommet->vertex[v].x = sommet->point_list->x + x; /*coordonnes sommet adjacent numero v*/
		sommet->vertex[v].y = sommet->point_list->y + y;
	}
}
