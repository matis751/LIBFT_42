#include "unistd.h"
#include "stdio.h"
#include "stdlib.h"
#include "errno.h"
#include "fcntl.h"
#include "LIBFT_42/libft.h"

# define BUFF_SIZE 1
typedef struct s_map
{
	char *buff;
	int size_x;
	int size_y;
	int player_nb;
    int piece_x;
    int piece_y;
    int state;
    char *piece_buff;
} t_map;

typedef struct s_filler
{
	int state;
	int player_nb;
} t_filler;

typedef struct s_piece
{
	int line;
	int row;
} t_piece;

/*ERROR.C*/
int		print_input_error(int errnum);
int		print_sys_error(int errnum);

/*INIT STRUCT*/

void *filler_init(t_filler **filler);
void *map_init(t_map **map);
void *piece_init(t_piece **piece);

/*READER.C*/

char *reader(t_map *map);
int len_reader(char *buff, int *line, int *col);

/*READER_DATA*/

int data_player(char *buff, t_map *map);
int data_map_size(char *buff, t_map *map);
int data_map_buff(t_map *map, int fd);
int data_map(char *buff, t_map *map, int fd);
int data_buff_checker(t_map *map, char *buff, int size);
int data_buff_checker_first_line(t_map *map, char *buff, int *len);
int ft_buff_data(t_map *map, int fd);
int data_piece(char *buff, t_map *map, int fd);
int data_piece_buff(char *buff, t_map *map, int fd);
int get_line_piece_size(char **tmp, char *buff, int fd);
int data_piece_size(char *buff, t_map *map, int fd);
int data_buff_piece_cheker(char *buff, t_map *map, int size);
int data_buff_checker(t_map *map, char *buff,  int size);
int data_map_checker(t_map *map, int x, int y, char *buff, int size);
int data_get_in_map(char *buff, t_map *map, int x);



/*PARSER.C*/

int player_parser(t_filler **tmp, t_map *map);

/*INIT.C*/

void *ft_joinner(char **tmp, char *buff);
void *ft_memalloc_2(char **buff);

/*UTILS.C*/
void *ft_joinner(char **tmp, char *buff);
void *ft_njoinner(char**tmp, char *buff, int len);
void *ft_memalloc_2(char **buff);

