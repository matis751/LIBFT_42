/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:23:50 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 19:34:18 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void destructor_sommet(t_list *s)
{
	int v;
	v = -1;
	s->visit_1 = -1;
	while(++v < s->nb_adj)
		if(s->vertex[v].sommet != NULL)
				destructor_sommet(s->vertex[v].sommet);
	free(s->point_list);
	s->point_list = NULL;
	free(s);
	s = NULL;
}
void destructor_pile(t_pile *pile)
{
	next(&pile);
	while(pile->pre)
	{
		pile_pre(&pile);
		free(pile->sv);
		pile->sv = NULL;
	}
	free(pile);
	pile = NULL;
}
void destructor_piece(t_piece *piece)
{
	while(piece->sv)
		piece_sv(&piece);
	while(piece->pre)
	{
		piece_pre(&piece);
		free(piece->sv->point);
		free(piece->sv);
		piece->sv->point = NULL;
		piece->sv = NULL;
	}
	free(piece->point);
	free(piece);
	piece->point = NULL;
	piece = NULL;
}
void destructor(t_list *sommet, t_pile *pile, t_piece *piece)
{
	destructor_sommet(sommet);
	destructor_piece(piece);
/*	printf("piece %p\n\n", piece);
	destructor_pile(pile);
	printf("pile %p\n\n", pile);
	*/
}
int main(void)
{
	int ret;
	int x = 0;
	int y = 0;
	int v = 0;
	char *buff = NULL;
	char *piece = NULL;
	t_list *sommet;
	static t_map *map;
	t_pile *pile;
	t_piece *str_piece;


	pile = NULL;
	str_piece = NULL;
	sommet = NULL;
	map = NULL;
	if(!(map = map_init()))
		return(0);
	if(!(sommet = list_init()))
		return(0);
	if(!(pile = pile_init()))
		return(0);
	if(!(str_piece = piece_init()))
		return(0);

		if(!parse(map, sommet, pile, str_piece, &buff, &piece))
			return(0);
		parse_piece(piece, str_piece);
		find_vertex(sommet, map, pile);
		pile->sommet = sommet;
		if(!buff)
			return(0);
		set_in(buff, pile);
		place_piece_p1(sommet, map, pile, str_piece);
		destructor(sommet, pile, str_piece);
}
