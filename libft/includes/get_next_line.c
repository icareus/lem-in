/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/17 00:50:39 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/09 06:19:59 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"

static int		gnl_dotheshit(char *buff, char **str)
{
	char	*bn_pos;
	char	*tmp;

	bn_pos = ft_strchr(buff, '\n');
	if (bn_pos)
	{
		*bn_pos = '\0';
		tmp = ft_strjoin(*str, buff);
		if (!tmp)
			return (-1);
		ft_strdel(str);
		*str = tmp;
		ft_memslide(buff, (bn_pos - buff + 1), BUFF_SIZE);
		return (1);
	}
	else
	{
		tmp = ft_strjoin(*str, buff);
		ft_strdel(str);
		*str = tmp;
		ft_bzero(buff, BUFF_SIZE);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static char		buff[BUFF_SIZE + 1];
	char			*tmp;
	int				ret_val;

	if (fd < 0)
		return (-1);
	ret_val = 0;
	tmp = NULL;
	while (!ret_val)
	{
		if (!*buff)
		{
			ret_val = read(fd, buff, BUFF_SIZE);
			if (ret_val <= 0)
			{
				gnl_dotheshit(buff, &tmp);
				break ;
			}
		}
		ret_val = gnl_dotheshit(buff, &tmp);
	}
	*line = tmp;
	return (ret_val);
}
