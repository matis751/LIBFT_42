/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_inside.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:52:10 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/29 13:52:12 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"
int player(char c)
{
	if(c == 'x' || c == 'X')
		return (2);
	if(c == 'o' || c == 'O')
		return (1);
	return (0);
}
void set_char(char *data, char buff)
{
	if(buff && data)
		if(buff != 0)
			if(ft_charchr(buff) > 0)
				*data = buff;
}
int coord_pile (t_pile *pile, int x, int y)
{
	if(pile)
		return(pile->x == x && pile->y == y);
	return (0);
}
char *find_coord(t_pile *pile, int x, int y, char buff)
{
	int ret;
	if(!pile)
		return(NULL);
	befor(&pile);
	while(!coord_pile(pile, x, y))
	{
		if(pile->sv)
			pile_sv(&pile);
		else
			break;
	}
	ret = player(buff);
	if(!pile->sommet)
		return(NULL);
	pile->sommet->player = ret;
	return(&pile->sommet->data);
}

void set_in(char *buff, t_pile *pile)
{
	int x = -1;
	int y = 0;
	int c = -1;

	if(!pile || !buff)
		return;
	while(buff[++x] && x < ft_strlen(buff) - 1)
	{
		++c;
		if(buff[x] == '\n')
		{
			y++;
			x++;
			c = 0;
		}
		set_char((find_coord(pile, c, y, buff[x])), buff[x]);
	}
}
