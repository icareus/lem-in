/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslide.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/02 13:28:08 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:39:27 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strslide(char *str, int slen)
{
	if (slen == -1)
		ft_bzero(str, ft_strlen(str));
	else
		ft_memslide(str, slen, ft_strlen(str));
}
