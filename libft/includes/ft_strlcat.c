/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 04:47:17 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 15:40:35 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dstl;
	size_t		srcl;
	size_t		catl;

	dstl = 0;
	srcl = 0;
	catl = 0;
	while (dst[dstl])
		dstl++;
	while (src[srcl])
		srcl++;
	if (size == 0 || dstl > size - 1)
		return (srcl + size);
	while ((dstl + catl < size - 1) && (src[catl]))
	{
		dst[dstl + catl] = src[catl];
		catl++;
	}
	dst[dstl + catl] = 0;
	return (dstl + srcl);
}
