#ifndef FILLER_H
#define FILLER_H
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

typedef struct s_infos
{
	int weight;
	int hight;
	int p;
} t_infos;

void new_line(int *x, int *y);
void	ft_bzero(void *s, size_t n);
void set_coord(t_list *file, int x, int y);
void	*ft_memset(void *b, int c, size_t len);
void get_infos(t_infos *infos);
void	ft_bzero(void *s, size_t n);
int bfs(char *buff);
void new_line(int *x, int *y);
char *ft_locat_str(char *str, char *locat);
char    *ft_strndup(const char *s1, int n);
size_t	ft_strlen(const char *s);
int		ft_strcmp(const char *s1, const char *s2);

#endif
