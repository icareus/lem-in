/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 05:24:43 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:33:52 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		i;

	i = 0;
	sub = malloc(sizeof(char) * len + 1);
	if (sub)
	{
		while (i < len)
		{
			sub[i] = s[start + i];
			i++;
		}
		sub[len] = '\0';
	}
	return (sub);
}
