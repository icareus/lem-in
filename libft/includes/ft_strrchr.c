/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 04:52:28 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:39:53 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*r;

	r = NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((r = ((char *)(s + i))));
		i++;
	}
	if (s[i] == (char)c)
		r = ((char *)(s + i));
	return (r);
}
