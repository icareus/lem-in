/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memslide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/04 18:03:33 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:48:38 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memslide(void *src, size_t slen, size_t maxlen)
{
	size_t		i;

	if (slen > maxlen)
	{
		ft_bzero(src, ft_strlen(src));
		return ;
	}
	i = 0;
	while (i + slen <= maxlen)
	{
		*(char *)(src + i) = *(char *)(src + i + slen);
		i++;
	}
	while (i <= maxlen)
	{
		*(char *)(src + i) = '\0';
		i++;
	}
}
