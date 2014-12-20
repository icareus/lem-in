/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 04:13:25 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 15:41:54 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		lens1;

	i = 0;
	lens1 = 0;
	while (s1[lens1])
		lens1++;
	while (s2[i] && i < n)
	{
		s1[lens1 + i] = s2[i];
		i++;
	}
	s1[lens1 + i] = 0;
	return (s1);
}
