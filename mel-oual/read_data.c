#include "LIBFT_42/libft.h"
#include "filler.h"
#include <stdio.h>

int data_player(char *buff, t_map *map) /*Cherche le numero de joueur*/
{
  char *tmp = NULL;

  tmp = ft_strstr(buff, "p1 : [mel-oual/mel-oual.filler]");
  if(tmp == NULL)
    tmp = ft_strstr(buff, "p2 : [mel-oual/mel-oual.filler]");
  if(tmp == NULL)
    return(-1);
  map->player_nb = ft_atoi(tmp + 1);
  return((map->player_nb == 1 || map->player_nb== 2) ? 1 : print_input_error(1));
}

int data_map_size(char *buff, t_map *map) /*cherche la taille de la map*/
{
  char *tmp_x = NULL;
  char *tmp_y = NULL;

  if(!(tmp_x = ft_strstr(buff, "Plateau")))
    return (-1);
  tmp_x += 8;
  tmp_y = tmp_x;
  while((*(++tmp_y) != ' ') && *(tmp_y))
    if(!(ft_isdigit(*tmp_y)))
      return (print_input_error(2));
  map->size_x = ft_atoi(tmp_x);
  tmp_x = tmp_y;
  while((*(++tmp_x) != ' ') && *(tmp_x))
    if(!(ft_isdigit(*tmp_x)))
      return (print_input_error(2));
  map->size_y = ft_atoi(tmp_y);
  if(map->size_y == 0 || map->size_x == 0)
      return (print_input_error(2));
  return(1);

}
int data_buff_checker_first_line(t_map *map, int *len)
{
    int x = *len;
      while(x++ <= 3 && map->buff[x])
        if(map->buff[x] != ' ')
          return(print_input_error(6));
      while(map->buff[x++] != '\n' && map->buff[x])
        if(!(ft_isdigit(map->buff[x])))
          return (print_input_error(6));
      if(x != map->size_x + 1)
        return (print_input_error(4));
      return(*len = x);
}
int data_buff_checker(t_map *map, char *buff,  int size)
{
  int x = 0;
  int y = -1;
  int ret = 0;

  while(x <= size && ++y <= map->size_y)
  {
    if(y == 0)
    {
      if(!(ret = data_buff_checker_first_line(map, &x)))
        return(ret);
    }
    else
    {
      while(x++ % 3) /*check les 3 premiers caracteres de la ligne il doit s'agir de numeros*/
        if(!(ft_isdigit(buff[x])))
          return (print_input_error(6));
      if(buff[x] != ' ') /*l'espace entre les 3 premiers caracteres et la map*/
        return (print_input_error(6));
      while(buff[++x] && x % map->size_x)/*tant que que x % size_x different de 0 c'est que la ligne est pas finis*/
        if(buff[x] != '.' && buff[x] != 'o' && buff[x] != 'O' 
             && buff[x] != 'x' && buff[x] != 'X')
            return(print_input_error(6));
      if(buff[x] != '\n') /*le dernier caractere de la ligne est un \n*/
        return(print_input_error(6));
      if(x % map->size_x + 1)
        return(print_input_error(6));
    }
  }
  return((y == map->size_y || x == size) ? 1 : print_input_error(6));
}
int data_map_buff(char *buff, t_map *map, int fd)
{
    int ret = 0;
    int size = ((map->size_x + 5) * (map->size_y + 1));

    if(!(buff = ft_strnew(size + 1)))
      return(-1);
    if((ret = read(fd, buff, size)) < 0)
      return(ret);
    buff[ret] = '\0';
    if(!(data_buff_checker(map, buff, size)))
      return(-1);
    map->buff = ft_strdup(buff);
    ft_strdel(&buff);
    return(1);
}
int get_line_piece_size(char **tmp_1, char *buff, int fd)
{
    int ret = 0;
    char *tmp = NULL;

    if(!(buff = ft_strnew(BUFF_SIZE)) || (!(tmp = ft_strnew(1))))
      return(-1);
    while(!(ft_strchr(tmp, '\n')))
    {
      if((ret = read(fd, buff, 1)) <= 0)
        return(ret);
      if(!(ft_joinner(&tmp, buff)))
        return(-1);
      ft_memalloc_2(&buff);
    }
    ft_strdel(&buff);
    *tmp_1 = tmp;
    return(1);
}

int data_piece_size(char *buff, t_map *map, int fd)
{
    char *piece = NULL;
    char *tmp_piece = NULL;
    char *tmp = NULL;

    get_line_piece_size(&tmp, buff, fd);
    if(!(piece = ft_strstr(tmp,"Piece")))
      return(-1);
    piece += 6;
    tmp_piece = piece + 1;
    while(*(tmp_piece++) != ' ')
      if(!(ft_isdigit(*tmp_piece)))
        return (print_input_error(8));
    map->piece_x = ft_atoi(piece);
    piece = tmp_piece;
    tmp_piece += 1;
    while(*(tmp_piece++) != ' ')
      if(!(ft_isdigit(*tmp_piece)))
        return (print_input_error(8));
    map->piece_y = ft_atoi(tmp_piece);
    ft_strdel(&tmp);
    return(1);
}
int data_buff_piece_cheker(char *buff, t_map *map, int size)
{
    int x = -1;
    int y = 0;
    while(buff[++x])
    {
      if(buff[x] != '*' && buff[x] != '.' && buff[x] != '\n')
        return(print_input_error(8));
      if(buff[x] == '\n' && x % map->piece_x)
        return (print_input_error(7));
      else
        y++;
    }
    if(y != map->piece_y || x != size)
      return (print_input_error(9));
    return(1);
}
int data_piece_buff(char *buff, t_map *map, int fd)
{
  int ret = 0;
  int size_piece = (map->size_x + 1) * (map->size_y);
  buff = ft_strnew(size_piece);
  if((ret = read(fd, buff, size_piece)) < 0)
    return(-1);
  buff[ret] = '\0';
  if(!(data_buff_piece_cheker(buff, map, size_piece)))
    return(-1);
  map->piece_buff = ft_strdup(buff);
  ft_strdel(&buff);
  return(1);
}
int data_map(char *first_block, t_map *map, int fd)
{
  char *buff = NULL;
  int ret = 0;/*si ret == 0 c'est que le buffer n'as
pas encore lu la piece la map ou le nb du joueur sion c'est une erreur */
  if((ret = data_player(first_block, map)) < 0)
    return(ret);
  if((ret = data_map_size(first_block, map)) < 0)/*prend la taille de la map*/
    return(ret);/****************STOP ICI****************/
  if((ret = data_map_buff(buff, map, fd)) < 0)/*prend la map, fd*/
    return(ret);
  if((ret = data_piece_size(buff, map, fd)) < 0) /*stock la piece*/
    return(ret);
  if((ret = data_piece_buff(buff, map, fd)) < 0)/*arret ici*/
    return(-1);
  return(1);
}
