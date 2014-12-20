/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 02:36:20 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 14:17:37 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_strjoin(const char *s1, const char *s2)
{
	size_t		src_len;
	size_t		s1_len;
	void		*ret;

	if (!(s1 || s2))
		ret = NULL;
	else if (!(s1 && s2))
		ret = s1 ? ft_strdup(s1) : ft_strdup(s2);
	else
	{
		src_len = (ft_strlen(s1) + ft_strlen(s2));
		ret = (char *)malloc(sizeof(char) * src_len + 1);
		if (ret)
		{
			s1_len = ft_strlen(s1);
			ft_memcpy(ret, s1, s1_len);
			ft_memcpy((ret + s1_len), s2, (src_len - s1_len) + 1);
		}
	}
	return (ret);
}
