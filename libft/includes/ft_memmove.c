/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:59:04 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:48:23 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	size_t		c;
	char		*ret;

	c = 0;
	ret = malloc(sizeof(char) * n);
	while (c <= n)
	{
		*(ret + c) = *(char*)(s2 + c);
		c++;
	}
	c = 0;
	while (c <= n)
	{
		*(char*)(s1 + c) = *(char*)(ret + c);
		c++;
	}
	ft_memdel((void **)&ret);
	return (s1);
}
