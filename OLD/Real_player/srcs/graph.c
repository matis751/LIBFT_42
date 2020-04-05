/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:40:15 by mel-oual          #+#    #+#             */
/*   Updated: 2019/12/17 11:47:02 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/list.h"
#include "../includes/graph.h"

void adr_vertex(t_list **file)
{
	return (0);

}
void is_vertex(t_list *file)
{
	int x;
	int y;
	int v;
	t_infos *infos;

	int weight = 17;
	int hight = 15; 
	x = -1;
	y = -1;
	v = 0;
	while(y < 2)
	{
		if(file->point_list->y + y <= hight && file->point_list->y + y >= 0)
			while(x < 2)
			{
				if(file->point_list->x + x <= weight && file->point_list->x + x >= 0)
				{
					file->vertex->adj[v].x = file->point_list->x + x;
					file->vertex->adj[v].y = file->point_list->y + y;
					(file->vertex->adj[v].y == 0 && file->vertex->adj[v].x == 0) ? NULL : adr_vertex(&file);
				}
				v++;
				x++;
			}
			x = -1;
			y++;
	}
}

