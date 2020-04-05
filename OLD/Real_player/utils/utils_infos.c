#include "../includes/filler.h"

char *ft_locat_str(char *str, char *locat)
{
	int x;
	char *chr;

	x = -1;
	if(str == NULL || locat == NULL)
		return (NULL);
	while(*str)
	{
		chr = ft_strndup(str, ft_strlen(locat));
		if(!(ft_strcmp(chr, locat)))
			return (str);
		free(chr);
		str++;
	}
	return (NULL);
}

char	*ft_strndup(const char *s1, int n)
{
	int		i;
	char	*res;

	i = 0;
	res = (char*)malloc(sizeof(char) * (n + 1));
	if (res == 0)
	{
		return (NULL);
	}
	while (i < n)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*s3;
	unsigned char	*s4;

	i = 0;
	s3 = (unsigned char*)s1;
	s4 = (unsigned char*)s2;
	while ((s3[i] || s4[i]) != 0)
	{
		if (s3[i] == s4[i])
		{
			i++;
		}
		else
			return (s3[i] - s4[i]);
	}
	return (0);
}
