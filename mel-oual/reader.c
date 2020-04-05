
#include "filler.h"
#include <stdio.h>

char *reader(t_map *map)
{
	int ret;
    char *tmp = NULL;
	char *buff = NULL;
    int fd;
    int line = -1;
    if((fd = open("test.txt", O_RDONLY)) == -1)
      return(NULL);
	if(!(buff = ft_strnew(BUFF_SIZE + 1)) || ((ret = read(fd, buff,0) == -1)))
		return(NULL);
    while(1)
	{
      if(map->state == 0)
      {
         while(line < 9)
         {
             if((ret = read(fd, buff, 1)) < 0)
               return(NULL);
             buff[ret] = '\0';
             if(!(ft_joinner(&tmp, buff)))
               return(NULL);
             if(ft_strchr(buff, '\n'))
               line++;
             if(!(ft_memalloc_2(&buff)))
       		return(NULL);
          }
         tmp[ft_strlen(tmp) - 2] = '\0';
       }
      if(!(data_map(tmp, map, fd)))
        return(NULL);
      break;
	}
	ft_strdel(&tmp);
	return(ret < 0 ? NULL : tmp);
}
