	/* ************************************************************************** */
	/*                                                                            */
	/*                                                        :::      ::::::::   */
	/*   place_piece.c                                      :+:      :+:    :+:   */
	/*                                                    +:+ +:+         +:+     */
	/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
	/*                                                +#+#+#+#+#+   +#+           */
	/*   Created: 2019/12/28 19:24:46 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 17:34:20 by mel-oual         ###   ########.fr       */
	/*                                                                            */
	/* ************************************************************************** */

#include "list.h"
	int set_player(t_list *sommet)
	{
		int x = -1;
		int ret = 0;
		sommet->visit_1 = -2;
		if(sommet->data == 'X' || sommet->data == 'x')
			sommet->player = 2;
		if(sommet->data == 'O' || sommet->data == 'o')
			sommet->player = 1;
		while(++x <= sommet->nb_adj)
		{
			if(sommet->vertex[x].sommet)
				if(sommet->vertex[x].sommet->visit_1 != -2)
					ret = set_player(sommet->vertex[x].sommet);
		}
		return (ret);
	}

	void find_way(t_list *p1, t_list *p2, t_ret *ret, int x)
	{
		if(p1->point_list->x < p2->point_list->x) /*p1 gauche || mm colonne  p2'*/
		{
			if(p1->point_list->x < p2->point_list->x) /*p1 gauche || mm colonne  p2'*/
			{
				if(p1->point_list->y <= p2->point_list->y)/*a gauche haut*/
					calcul_1(ret, p1, p2, x);
				if(p1->point_list->y > p2->point_list->y)
					calcul_2(ret, p1, p2, x);
			}
		}
		if(p1->point_list->x > p2->point_list->x)
		{
			if(p1->point_list->y <= p2->point_list->y)
				calcul_3(ret, p1, p2, x);
			if(p1->point_list->y > p2->point_list->y)
				calcul_4(ret, p1, p2, x);
		}
	}
	void find_same(t_list *p1, t_list *p2, t_ret *ret, int x)
	{
		if(p1->point_list->x == p2->point_list->x)
		{
			if(p1->point_list->y < p2->point_list->y)
				calcul_5(ret, p1, p2, x);
			if(p1->point_list->y > p2->point_list->y)
				calcul_6(ret, p1, p2, x);
		}
		if(p1->point_list->y == p2->point_list->y)
		{
			if(p1->point_list->x < p2->point_list->x)
				calcul_7(ret, p1, p2, x);
			if(p1->point_list->x > p2->point_list->x)
				calcul_8(ret, p1, p2, x);
		}
	}

	void distance_p1_p2(t_list *sommet_p1, t_list *sommet_p2, t_ret *ret, int nb_3)
	{
		int x = -1;
		static char c = '1';
		sommet_p1->visit_3 = nb_3;
		ret->num = 0;
		ret->note = 0;

		if((sommet_p1->point_list->x != sommet_p2->point_list->x) || (sommet_p1->point_list->y != sommet_p2->point_list->y))
		{
			while(++x <= sommet_p1->nb_adj)
			{
				if(sommet_p1->vertex[x].sommet)
				{
					if((sommet_p1->point_list->x != sommet_p2->point_list->x) && (sommet_p1->point_list->y != sommet_p2->point_list->y))
						find_way(sommet_p1, sommet_p2, ret, x);
					else
						find_same(sommet_p1, sommet_p2, ret, x);
				}
			}
			if(sommet_p1->vertex[ret->num].sommet && sommet_p1->vertex[ret->num].sommet->visit_3 != nb_3)
			{
	/*			sommet_p1->data = c++;
	 */
				ret->nb++;
				distance_p1_p2(sommet_p1->vertex[ret->num].sommet, sommet_p2, ret, nb_3);
			}
		}
	}

void find_sommet_p2(t_list *sommet_p1, t_list *sommet_p2, t_ret *ret, int nb_2, t_map *map)
{
		int x;
		x = -1;
		static int nb_3 = 1;

		sommet_p2->visit_2 = nb_2;
		if(sommet_p2->player != map->p)
		{
			distance_p1_p2(sommet_p1, sommet_p2, ret, nb_3);
			sommet_p1->step = ret->nb;
			ret->nb = 0;
			nb_3++;
		}
		while(++x < sommet_p2->nb_adj)
			if(sommet_p2->vertex[x].sommet && sommet_p2->vertex[x].sommet->visit_2 != nb_2)
				find_sommet_p2(sommet_p1, sommet_p2->vertex[x].sommet, ret, nb_2, map);
}
void find_sommet_p1(t_list *sommet_p1, t_list *sommet_p2, t_ret *ret, t_map *map)
{
		int x;
		static int nb_2 = 1;
		x = -1;

		sommet_p1->visit_1 = 0;
		if(sommet_p1->player == map->p)
		{
			find_sommet_p2(sommet_p1, sommet_p2, ret, nb_2, map);
			nb_2++;
		}
		while(++x <= sommet_p1->nb_adj)
			if(sommet_p1->vertex[x].sommet && sommet_p1->vertex[x].sommet->visit_1 != 0)
				find_sommet_p1(sommet_p1->vertex[x].sommet, sommet_p2, ret, map);
}

t_list *find_closest(t_list *sommet, t_list **var, t_piece *piece, t_pile *pile, t_map *map)
{
		int x = -1;
		static int nb = 1;
		static t_list *tmp = NULL;
		sommet->visit_1 = nb;
		if(sommet->step != 0 && test_pose_2(sommet, piece, pile, map))
		{
			if(!tmp)
				tmp = sommet;
			if(sommet->step < tmp->step)
				tmp = sommet;
			*var = tmp;
		}
		while(++x <= sommet->nb_adj)
		{
			if(sommet->vertex[x].sommet && sommet->vertex[x].sommet->visit_1 != nb)
				find_closest(sommet->vertex[x].sommet, var, piece, pile, map);
		}
		return(tmp);
}
int nb_ennemi(t_list *sommet, int joueur)
{
		int x = -1;
		while(++x <= sommet->nb_adj)
			if(sommet->vertex[x].sommet)
				if(sommet->vertex[x].sommet->player != joueur 
						&& sommet->vertex[x].sommet->player != 0)
					sommet->nb_player++;
		return(sommet->nb_player);
	}
	void most_vertex(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map)
	{
		int x = -1;
		int joueur = map->p;
		static t_list *tmp = NULL;
		sommet->visit_1 = -1;

		nb_ennemi(sommet, joueur);
		if(!tmp)
			tmp = sommet;
		while(++x <= sommet->nb_adj)
			if(sommet->vertex[x].sommet && sommet->vertex[x].sommet->visit_1 != -1)
				most_vertex(sommet->vertex[x].sommet, piece, pile, map);
	}
	void place_piece_p1(t_list *sommet, t_map *map, t_pile *pile, t_piece *piece)
	{
		t_ret *ret = NULL;
		t_list *tmp = NULL;
		ret = ret_init();
		set_player(sommet);
		find_sommet_p1(sommet, sommet, ret, map);
		most_vertex(sommet, piece, pile, map);
		tmp = poseur(sommet, piece, pile, map, 2);
		if(tmp != NULL)
		{
			if(tmp->point_list->x == 0 && tmp->point_list->y == 0)
				printf("%d %d\n", tmp->point_list->y, tmp->point_list->x);
			else
				printf("%d %d\n", tmp->point_list->y, tmp->point_list->x);
		}
		else
			printf("0 0\n");
}
