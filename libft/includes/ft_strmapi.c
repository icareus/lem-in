/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 03:36:38 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 15:41:27 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*dup;
	int		len;

	dup = ft_strdup(s);
	len = ft_strlen(dup);
	while (len)
	{
		len--;
		dup[len] = f(len, s[len]);
	}
	return (dup);
}
