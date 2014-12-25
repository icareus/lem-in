/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 19:15:59 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/25 05:24:46 by lefebvre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *src, int size)
{
	void	*ret;
	int		i;

	i = 0;
	ret = malloc(size);
	while (i < size)
	{
		((char *)ret)[i] = ((char *)src)[i];
		i++;
	}
	return (ret);
}
