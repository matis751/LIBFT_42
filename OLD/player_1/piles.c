/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piles.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 21:38:22 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 19:50:05 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void pile_pre(t_pile **pile)/*pbm ds ces deux fonctions*/
{
	t_pile *tmp = NULL;
	t_pile *tmp_2 = NULL;

	tmp = *pile;
	tmp_2 = *pile;
	if(tmp->pre)
	{
		tmp = tmp->pre;
		tmp->sv = tmp_2;
		*pile = tmp;
	}
}
void pile_sv(t_pile **pile)
{
	t_pile *tmp = NULL;
	t_pile *tmp_2 = NULL;

	tmp = *pile;
	tmp_2 = *pile;
	tmp = tmp->sv;
	tmp ? tmp->pre = tmp_2 : NULL;
	*pile = tmp;
}
void set_pile(t_pile *pile, t_list *sommet, int x, int y, int v)
{
	next(&pile);
	pile->sv = pile_init(); /*creer un nouvel element de pile et va a l'adresse suivante*/
	pile_sv(&pile);
	pile->sommet = sommet->vertex[v].sommet;/*met l'adress qui correspond au sommet ds pile*/
	pile->x = sommet->point_list->x + x;/*met les coordonnes dans pile*/
	pile->y = sommet->point_list->y + y;
}
