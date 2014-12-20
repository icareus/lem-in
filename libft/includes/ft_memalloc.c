/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 17:26:36 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:47:08 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void		*alc;

	alc = size ? malloc(sizeof(char) * size) : NULL;
	while (alc && size--)
		*(char *)(alc + size) = '\0';
	return (alc);
}
