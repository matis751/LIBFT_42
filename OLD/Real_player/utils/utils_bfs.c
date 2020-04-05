/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bfs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 11:21:47 by mel-oual          #+#    #+#             */
/*   Updated: 2019/12/17 11:31:20 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include "../includes/graph.h"
#include "../includes/list.h"

void new_line(int *x, int *y)
{
	*x = -1;
	*y += 1;
}
void set_coord(t_list *file, int x, int y)
{
	file->point_list->x = x;
	file->point_list->y = y;
}

