/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:19:28 by mel-oual          #+#    #+#             */
/*   Updated: 2020/01/27 19:54:24 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "list.h"

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}
int	is_digit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
char		*ft_strstr(const char *meule, const char *aiguille)
{
	int		i;
	int		i2;
	int		len;
	char	*meule2 = NULL;

	i2 = 0;
	i = 0;
	len = 0;
	meule2 = (char *)meule;
	while (aiguille[len])
		len++;
	if(len == 0)
		return (meule2);
	while(meule && meule2[i])
	{
		while (meule2[i + i2] == aiguille[i2] && meule2[i + i2] &&
				aiguille[i2])
			i2++;
		if (i2 == len)
			return (meule2 + i);
		i++;
		i2 = 0;
	}
	return (0);
}
int					ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t			i;
	unsigned char	*s1 = NULL;
	unsigned char	*s2 = NULL;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	i = 0;
	while (n > 0 && s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
		n--;
	}
	if (n == 0)
		return (0);
	return (s1[i] - s2[i]);
}
