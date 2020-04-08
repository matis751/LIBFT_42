#include "filler.h"

int data_first_read(char *buff, char **tmp_2, int fd)
{
    int line = -1;
    char *tmp = NULL;
    int ret = 0;

    tmp = *tmp_2;
	if(!(buff = ft_strnew(BUFF_SIZE + 1)) || ((ret = read(fd, buff,0) == -1)))
		return(-1);

     while(line < 9)
     {
         if((ret = read(fd, buff, 1)) < 0)
           return(-1);
         buff[ret] = '\0';
         if(!(ft_joinner(&tmp, buff)))
           return(-1);
         if(ft_strchr(buff, '\n'))
           line++;
         if(!(ft_memalloc_2(&buff)))
   		return(-1);
      }
    tmp[ft_strlen(tmp) - 2] = '\0';
    *tmp_2 = tmp;
    return(1);
}

char *reader(t_map *map)
{
    char *tmp = NULL;
	char *buff = NULL;
    int fd;
    if((fd = open("test.txt", O_RDONLY)) == -1)
      return(NULL);
    while(1)
	{
      if(map->state == 0)
      {
        if((data_first_read(buff, &tmp, fd) < 0))
          return(NULL);
      }
      if(!(data_map(tmp, map, fd)))
        return(NULL);
      break;
	}
    while(1);
	return(tmp);
}
