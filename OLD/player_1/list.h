#ifndef LIST_H
#define LIST_H
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <limits.h>
#include "gnl/gnl.h"

typedef struct s_coord
{
	int x;
	int y;
	struct s_list *sommet;
} t_coord;

typedef struct s_pile
{
	struct s_pile *pre;
	int x;
	int y;
	struct s_pile *sv;
	struct s_list *sommet;
} t_pile;

typedef struct s_list
{
	struct s_list *pre;
	t_coord *point_list;
	int player;
	int visit_1;
	int visit_2;
	int visit_3;
	int visit_4;
	long int pose_x;
	long int pose_y;
	char data;
	int nb_adj;
	int nb_player;
	int step;
	t_coord vertex[8];
} t_list;

typedef struct s_map
{
	int hight;
	int weight;
	int p;
} t_map;

typedef struct s_ret
{
	int note;
	int nb;
	int num;
} t_ret;

typedef struct s_path
{
	struct s_path *pre;
	int nb;
	t_coord *point;
	struct s_path *sv;
} t_path;

typedef struct s_piece
{
	struct s_piece *pre;
	t_coord *point;
	int num;
	int nb_p;
	int poser;
	int max_x;
	int max_y;
	struct s_piece *sv;

} t_piece;

char **set_tab(char *buff);
void pile_sv(t_pile **pile);
void pile_pre(t_pile **pile);
void set_pile(t_pile *pile, t_list *sommet, int x, int y, int v);
void set_coord(t_list *sommet, t_pile *pile, int x, int y, int v);
t_map *map_init();
t_pile *pile_init();
t_ret *ret_init();
t_coord *init_coord();
t_list *attach(t_list *init, t_list *sommet);
t_list *list_init();
t_path *path_init();
t_piece *piece_init();
void path_init_sv(t_path **path);
int compar_point(t_pile **pile, t_coord *vertex);
t_list *coord_sommet(t_coord *vertex, t_pile *pile, t_list *sommet, int v);
void find_vertex(t_list *sommet, t_map *map, t_pile *pile);
void set_vertex(t_list *sommet, int x, int y, int v);
void next(t_pile **pile);
void befor(t_pile **pile);
int list_coord(t_list *sommet, t_list *sommet_2);

int nb_ennemi(t_list *sommet, int joueur);
void set_in(char *buff, t_pile *pile);
char *find_coord(t_pile *pile, int x, int y, char buff);
int coord_pile (t_pile *pile, int x, int y);
void set_char(char *c, char buff);
t_list *find_closest(t_list *sommet, t_list **var, t_piece *piece, t_pile *pile, t_map *map);
void path_sv(t_path **path);
void find_short(t_list *sommet, t_pile *pile);
void parse_piece(char *piece, t_piece *struct_piece);
void printer(t_list *sommet, t_map *map, t_pile *pile);
void piece_sv(t_piece **piece);
void piece_pre(t_piece **piece);
void place_piece_p1(t_list *sommet, t_map *map, t_pile *pile, t_piece *piece);
t_list *poseur(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map, int nb);
void calcul_1(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_2(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_3(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_4(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_5(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_6(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_7(t_ret *ret, t_list *p1, t_list *p2, int x);
void calcul_8(t_ret *ret, t_list *p1, t_list *p2, int x);
int test_pose(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map);
int test_pose_2(t_list *sommet, t_piece *piece, t_pile *pile, t_map *map);
int is_digit(int c);
char	*ft_strstr(const char *meule, const char *aiguille);
int parse(t_map *map, t_list *sommet, t_pile *pile, t_piece *piece, char **buff
, char **piece_txt);
void ft_strdel(char **as);
int ft_strncmp(const char *str1, const char *str2, size_t n);
int ft_charchr(char c);
size_t ft_strlen(const char *s);
#endif
