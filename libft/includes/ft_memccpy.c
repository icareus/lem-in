/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:57:49 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:47:23 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t		i;
	char		cc;

	i = 0;
	cc = (char)c;
	while (i < n)
	{
		*(char*)(s1 + i) = *(char*)(s2 + i);
		if (*(char*)(s2 + i) == cc)
		{
			return (s1 + i + 1);
		}
		i++;
	}
	return (NULL);
}
