/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_vertex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 14:44:06 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 20:33:03 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void set_vertex(t_list *sommet, int x, int y, int v)
{
	t_list *tmp;
	tmp = NULL;
	tmp = list_init();
	if(sommet == NULL)
		return;
	if(!(sommet->vertex[v].sommet = attach(tmp, sommet)))/*initialise le sommet adjacent et le relie a son pere*/
		return;
	sommet->vertex[v].sommet->point_list->x = sommet->point_list->x + x; /*coordonnes du sommet adj*/
	sommet->vertex[v].sommet->point_list->y = sommet->point_list->y + y;
}
