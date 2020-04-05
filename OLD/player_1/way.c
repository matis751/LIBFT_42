/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   way.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 18:49:49 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/06 23:32:12 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void calcul_1(t_ret *ret, t_list *p1, t_list *p2, int x)/*1 gauchge haut par rapport au point 2*/
{
	int note = 0;
	if(p1->point_list->x < p1->vertex[x].sommet->point_list->x && p2->point_list->x >= p1->vertex[x].sommet->point_list->x)
		note++;
	if(p1->point_list->y < p1->vertex[x].sommet->point_list->y && p2->point_list->y >= p1->vertex[x].sommet->point_list->y)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}

void calcul_2(t_ret *ret, t_list *p1, t_list *p2, int x)
{
	int note = 0;
	if(p1->point_list->x < p1->vertex[x].sommet->point_list->x && p2->point_list->x >= p1->vertex[x].sommet->point_list->x)
		note++;
	if(p1->point_list->y > p1->vertex[x].sommet->point_list->y && p2->point_list->y <= p1->vertex[x].sommet->point_list->y)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}

void calcul_3(t_ret *ret, t_list *p1, t_list *p2, int x)
{
	int note = 0;
	if(p1->point_list->x > p1->vertex[x].sommet->point_list->x && p2->point_list->x <= p1->vertex[x].sommet->point_list->x)
		note++;
	if(p1->point_list->y < p1->vertex[x].sommet->point_list->y && p2->point_list->y >= p1->vertex[x].sommet->point_list->y)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}

void calcul_4(t_ret *ret, t_list *p1, t_list *p2, int x)
{
	int note = 0;
	if(p1->point_list->x > p1->vertex[x].sommet->point_list->x && p2->point_list->x <= p1->vertex[x].sommet->point_list->x)
		note++;
	if(p1->point_list->y > p1->vertex[x].sommet->point_list->y && p2->point_list->y <= p1->vertex[x].sommet->point_list->y)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}

void calcul_5(t_ret *ret, t_list *p1, t_list *p2, int x)/*1 gauchge haut par rapport au point 2*/
{
	int note = 0;
	if(p1->point_list->y < p1->vertex[x].sommet->point_list->y && p2->point_list->y >= p1->vertex[x].sommet->point_list->y)
		note++;
	if(p1->point_list->x == p1->vertex[x].sommet->point_list->x && p2->point_list->x == p1->vertex[x].sommet->point_list->x)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}


void calcul_6(t_ret *ret, t_list *p1, t_list *p2, int x)/*1 gauchge haut par rapport au point 2*/
{
	int note = 0;
	if(p1->point_list->x == p1->vertex[x].sommet->point_list->x && p2->point_list->x == p1->vertex[x].sommet->point_list->x)
		note++;
	if(p1->point_list->y > p1->vertex[x].sommet->point_list->y && p2->point_list->y <= p1->vertex[x].sommet->point_list->y)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}

void calcul_7(t_ret *ret, t_list *p1, t_list *p2, int x)/*1 gauchge haut par rapport au point 2*/
{
	int note = 0;
	if(p1->point_list->y == p1->vertex[x].sommet->point_list->y && p2->point_list->y == p1->vertex[x].sommet->point_list->y)
		note++;
	if(p1->point_list->x < p1->vertex[x].sommet->point_list->x && p2->point_list->x >= p1->vertex[x].sommet->point_list->x)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}

void calcul_8(t_ret *ret, t_list *p1, t_list *p2, int x)/*1 gauchge haut par rapport au point 2*/
{
	int note = 0;
	if(p1->point_list->y == p1->vertex[x].sommet->point_list->y && p2->point_list->y == p1->vertex[x].sommet->point_list->y)
		note++;
	if(p1->point_list->x > p1->vertex[x].sommet->point_list->x && p2->point_list->x <= p1->vertex[x].sommet->point_list->x)
		note++;
	if(note > ret->note)
	{
		ret->num = x;
		ret->note = note;
	}
}
