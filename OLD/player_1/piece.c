/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 17:40:01 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 19:18:30 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

t_piece *piece_init()
{
	t_piece *piece;
	piece = (t_piece *)malloc(sizeof(t_piece));
	piece->pre = NULL;
	piece->sv = NULL;
	piece->nb_p = 0;
	piece->num = 0;
	piece->poser = 0;
	piece->max_x = 0;
	piece->max_y = 0;
	piece->point = init_coord();
	return (piece);
}
void piece_sv(t_piece **piece)
{
	t_piece *tmp;
	t_piece *tmp_2;
	tmp = *piece;
	tmp_2 = *piece;
	if(tmp->sv)
	{
		tmp = tmp->sv;
		tmp->pre = tmp_2;
		*piece = tmp;
	}
}

void piece_pre(t_piece **piece)
{
	t_piece *tmp;
	t_piece *tmp_2;
	tmp = *piece;
	tmp_2 = *piece;
	if(tmp->pre)
	{
		tmp = tmp->pre;
		tmp->sv = tmp_2;
		*piece = tmp;
	}
}
