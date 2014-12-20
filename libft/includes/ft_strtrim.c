/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 06:26:05 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:33:15 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char		*trim;
	size_t		start_offset;
	size_t		end_offset;
	size_t		len;

	len = ft_strlen(s);
	start_offset = 0;
	end_offset = 0;
	while (start_offset < len && ft_strchr(" \t\n", s[start_offset]))
		start_offset++;
	while (end_offset < len && ft_strchr(" \t\n", s[len - end_offset - 1]))
		end_offset++;
	trim = ft_strsub(s, start_offset, len - (start_offset + end_offset));
	return (trim);
}
