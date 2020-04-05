
#include "filler.h"
void *ft_memalloc_2(char **buff)
{
	char *tmp;
	tmp = NULL;
	tmp = *buff;
	ft_strdel(&tmp);
	if(!(tmp = ft_strnew(BUFF_SIZE + 1)))
		return(NULL);
	*buff = tmp;
	return((void *)*buff);
}
void *ft_joinner(char **tmp, char *buff)
{
	char *s1 = NULL;
	char *s2 = NULL;
	char *s3 = NULL;

    if(*tmp == NULL)
      if(!(*tmp = ft_strnew(1)))
        return(NULL);
	s1 = *tmp;
	s2 = buff;
	if(!(s3 = ft_strjoin(s1, s2)))
		return(NULL);
	ft_strdel(&s1);
	if(!(s1 = ft_strdup(s3)))
		return(NULL);
	ft_strdel(&s3);
	*tmp = s1;
	return((void *)*tmp);
}

