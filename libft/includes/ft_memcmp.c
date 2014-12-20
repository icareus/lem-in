/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 22:33:36 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:47:42 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(char*)(s1 + i) != *(char*)(s2 + i))
		{
			i = (size_t)
				(*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
			return ((int)i);
		}
		i++;
	}
	return (0);
}
