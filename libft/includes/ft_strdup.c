/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 22:53:22 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 14:17:31 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*new;

	len = 0;
	while (s1[len])
	{
		len++;
	}
	new = malloc(sizeof(char) * len);
	if (new)
	{
		while (len)
		{
			new[len] = s1[len];
			len--;
		}
		new[0] = s1[0];
	}
	return (new);
}
