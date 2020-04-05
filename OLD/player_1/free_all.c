/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 00:26:13 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/27 22:04:14 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void free_graph(t_list *sommet)
{
	sommet->visit_1 = -1;
	int x = -1;
	while(++x <= sommet->nb_adj)
		if(sommet->vertex[x].sommet)
			if(sommet->vertex[x].sommet->visit_1 != -1)
				free_graph(sommet->vertex[x].sommet);
	free(sommet->point_list);
	free(sommet);
}
void free_all(char *buff, char *p, t_piece *piece, t_pile *pile, t_list *sommet, t_map *map)
{
	while(piece->pre)
		piece_pre(&piece);
	while(piece->sv)
	{
		piece_sv(&piece);
		free(piece->pre);
	}
	free(piece);
	while(pile->pre)
		pile_pre(&pile);
	while(pile->sv)
	{
		pile_sv(&pile);
		free(pile->pre);
	}
	free(pile);
	free_graph(sommet);
}
