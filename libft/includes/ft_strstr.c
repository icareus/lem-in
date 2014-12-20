/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 21:14:16 by abarbaro          #+#    #+#             */
/*   Updated: 2014/03/30 03:48:59 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		c;

	i = 0;
	c = 0;
	if (!*s2)
		return ((char*)s1);
	while (s1[i])
	{
		if (!s2[c])
			return ((char*)s1 + i);
		else if (s2[c] == s1[i + c])
			c++;
		else
		{
			c = 0;
			i++;
		}
	}
	return (NULL);
}
