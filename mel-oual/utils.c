
#include "LIBFT_42/libft.h"
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
  char *ret = NULL;

  s2 = *tmp;
  if(s2 == NULL)
    s2 = ft_strnew(1);
  if(!(s1 = ft_strnew(ft_strlen(s2) + ft_strlen(buff) + 1)))
    return(NULL);
  ret = s1;
  while(*s2)
    *(s1++) = *(s2++);
  while(*buff)
    *(s1++) = *(buff++);
  *s1 = '\0';
  *tmp = ret;
  return((void *)ret);
}

void *ft_njoinner(char **tmp, char *buff, int len)
{
    char *s1 = NULL;
    char *s2 = NULL;
    char *ret = NULL;


  s2 = *tmp;
  if(s2 == NULL)
    s2 = ft_strnew(1);
 if(!(s1 = ft_strnew(ft_strlen(s2) + len + 2)))
   return(NULL);
  ret = s1;
  while(*s2)
    *(s1++) = *(s2++);
  while(len--)
    *(s1++) = *(buff++);
  *s1 = '\0';
  *(++s1) = '\n';
  *tmp = ret;
  return((void *)s1);
}
