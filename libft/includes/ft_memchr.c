/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 21:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:47:33 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*ptr;

	ptr = (char *)s;
	while (n)
	{
		if (*(char *)(ptr) == (char)c)
			return (ptr);
		ptr++;
		n--;
	}
	return (NULL);
}
