/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-oual <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 18:15:33 by mel-oual          #+#    #+#             */
/*   Updated: 2019/11/08 16:08:31 by mel-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	num_len(unsigned long long n, int base)
{
	int		len;

	len = 1;
	while ((n /= base))
		len++;
	return (len);
}

char		*ft_ulltoa_base(unsigned long long n, int base)
{
	char	*ret;
	int		len;
	char	*base_digits;

	if (base < 17)
		base_digits = "0123456789abcdef";
	else
	{
		base_digits = "0123456789ABCDEF";
		base = 16;
	}
	len = num_len(n, base);
	if ((ret = ft_strnew(len)))
	{
		while (len--)
		{
			ret[len] = base_digits[n % base];
			n /= base;
		}
	}
	return (ret);
}
