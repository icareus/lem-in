/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 07:52:02 by abarbaro          #+#    #+#             */
/*   Updated: 2014/11/18 00:19:44 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_strsplit(const char *s, char c)
{
	char	**ret;
	int		i;
	int		x;
	int		y;

	ret = malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	i = 0;
	y = 0;
	x = 0;
	ret[x] = NULL;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && (i == 0 || (s[i] != c && s[i - 1] == c)))
		{
			x++;
			while (s[i + y] != c)
				y++;
			ret[x - 1] = ft_strsub(s, i, y);
			i += y;
			y = 0;
		}
	}
	return (ret);
}
