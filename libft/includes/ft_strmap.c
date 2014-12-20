/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 02:23:38 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 15:41:12 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dup;
	int		len;

	dup = ft_strdup(s);
	len = ft_strlen(dup);
	while (len)
	{
		len--;
		dup[len] = f(s[len]);
	}
	return (dup);
}
