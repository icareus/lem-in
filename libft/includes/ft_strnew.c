/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/10 15:47:26 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:41:12 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*new;

	new = (char *)malloc(sizeof(char) * size);
	while (size)
	{
		size--;
		new[size] = '\0';
	}
	return (new);
}
