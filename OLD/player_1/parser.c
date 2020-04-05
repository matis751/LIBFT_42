#include "list.h"

void get_map(char *line, t_map *map)
{
	int x;
	int tmp;
	char *read = NULL;

	x = 0;
	map->weight = 0;
	map->hight = 0;
	if(!line || line[0] == '\0')
		return ;
	while(line[x])
	{
		if(line[x] == '\n')
			return;
		tmp = 0;
		while(is_digit(line[x]) == 1 && line[x])
		{
			tmp += line[x] - 48;
			if(is_digit(line[x + 1]) == 1)
				tmp *= 10;
			x++;
			if(line[x] == '\n')
				return;
		}
		if(map->hight == 0)
			map->hight = tmp;
		else if(map->weight == 0)
			map->weight = tmp;
		x++;
	}
}
int ft_charchr(char c)
{
	char tab [6] = {'o', 'x', 'O', 'X', '.', '\n'};
	int x;
	x = -1;

	while(++x < 6)
	{
		if(c == tab[x])
			return(1);
		}
	return(0);
}
char *get_buff(char *line)
{
	char *debut = NULL;
	char *fin = NULL;
	char *buff = NULL;
	char *tmp = NULL;
	int ret;
	int x;

	x = 0;
	ret = 0;
	debut = ft_strstr(line, "000");
	fin = ft_strstr(line, "Piece");
	buff = (char *)malloc(sizeof(char) * (fin - debut) + 1);
	tmp = buff;
	while(debut < fin)
	{
		if((ret = ft_charchr(*debut)) > 0)
		{
			*buff = *debut;
			buff++;
		}
		debut++;
	}
	*(buff) = '\0';
	return(tmp);
}
void ajoute_rt(char **line)
{
	int x;
	char *tmp = NULL;
	char *tmp_2 = NULL;
	x = -1;
	tmp_2 = ft_strdup(*line);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(tmp_2) + 2);
	while(tmp_2[++x])
		tmp[x] = tmp_2[x];
	tmp[x] = '\n';
	tmp[x + 1] = '\0';
	free(*line);
	*line = ft_strdup(tmp);
}

int parse(t_map *map, t_list *sommet, t_pile *pile, t_piece *piece, char **tbuff, char **tpiece_txt)
{
	char *line = NULL;
	char *tmp_2 = NULL;
	char *tmp = NULL;
	char *buff = NULL;
	char *piece_txt = NULL;
	char *number = NULL;
	int fd;
	int lev = 0;
	int len = 0;
	int ret = 0;
	int x = 0;
	int u = 1;

/*	while ((ret = get_next_line(0, &line)) > 0)
	{
		ajoute_rt(&line);
		if(tmp == NULL)
			tmp = ft_strdup(line);
		else
		{
			tmp_2 = ft_strjoin(tmp, line);
			free(tmp);
			tmp = ft_strdup(tmp_2);
			free(tmp_2);
		}
		ft_strdel(&line);
	}*/

		gnl(0,&tmp);
		if (ft_strstr(tmp, "exec p1 : [players/abanlin.filler]") == 0)
			map->p = 1;
		if (map->p == 0 && (ft_strstr(tmp, "exec p2 : [players/abanlin.filler]") == 0))
			map->p = 2;
		ft_strstr(tmp, "Plateau") ? get_map(ft_strstr(tmp, "Plateau") + 7, map) : NULL;
		buff = (get_buff(ft_strstr(tmp, "Plateau")));
		ft_strstr(ft_strstr(tmp, "Piece"), "\n") ? piece_txt = ft_strdup((ft_strstr(ft_strstr(tmp, "Piece"), "\n") + 1)) : NULL;
		*tbuff = buff ? ft_strdup(buff) : NULL;
		*tpiece_txt = piece_txt ? ft_strdup(piece_txt) : NULL;
		return(tbuff && tpiece_txt ? 1 : 0);
}
