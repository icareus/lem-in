/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 06:09:22 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/25 03:17:33 by lefebvre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

int		is_room(char *line)
{
	while (*line && *line != ' ')
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (*line == '-')
		line++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != ' ')
		return (0);
	line++;
	if (*line == '-')
		line++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != '\0')
		return (0);
	return (1);
}

int		is_path(char *line)
{
	if (ft_strchr(line, '-'))
		return (1);
	else
		return (0);
}

t_room	*init_room(char *line, int room_flag)
{
	t_room		*newroom;
	int			i;

	i = 0;
	newroom = malloc(sizeof(t_room));
	while (line[i] != ' ')
		i++;
	newroom->flag = room_flag;
	newroom->name = ft_memdup(line, i);
	while (line[i] == ' ')
		i++;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	newroom->y = ft_atoi(line + i);
	return (newroom);
}

t_path	*init_path(char *line)
{
	t_path		newpath;
	int			score_pos;

	score_pos = (int)ft_strlchr(line, '-');
	newpath.door1 = ft_memdup(line, score_pos);
	newpath.door2 = ft_strdup(line + score_pos);
	return(ft_memdup(&newpath, sizeof(t_path)));
}

int		is_command(char *line)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ("##START", line))
			return (STARTROOM);
		else if (ft_strequ("##END", line))
			return (ENDROOM);
		else
			return (NORMAL);
	}
	else
		return (-1);
}
