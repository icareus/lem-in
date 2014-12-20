/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 11:01:00 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:46:57 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		i_len(int i)
{
	int		n;

	n = 1;
	while (i /= 10)
		n++;
	return (n);
}

char			*ft_itoa(int n)
{
	int		len;
	char	*ret;
	int		i;
	int		sign;

	if (n < -2147483647)
		return (ft_strdup("-2147483648"));
	sign = IS_NEG(n);
	len = i_len(n) + sign;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (ret);
	ret[len] = '\0';
	i = 0;
	while (len - i - sign)
	{
		ret[len - i - 1] = '0' + ABS(n % 10);
		n /= 10;
		i++;
	}
	if (sign)
		*ret = '-';
	return (ret);
}
