/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 06:09:22 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/27 16:20:56 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lemin.h"

int		is_command(char *line)
{
	if (*line == '#')
	{
		if (ft_strequ("##start", line))
			return (STARTROOM);
		else if (ft_strequ("##end", line))
			return (ENDROOM);
		else
			return (NORMAL);
	}
	else
		return (0);
}

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

int		is_path(char *line, t_list *rooms)
{
	t_path		tmp;

	if (ft_strchr(line, '-'))
	{
		tmp.door1 = ft_strsub(line, 0, ft_strlchr(line, '-'));
		tmp.door2 = ft_strdup(line + ft_strlchr(line, '-') + 1);
		if ((get_room_by_name(tmp.door1, rooms)
			&& get_room_by_name(tmp.door2, rooms)))
		{
			free(tmp.door1);
			free(tmp.door2);
			return (1);
		}
		else
		{
			free(tmp.door1);
			free(tmp.door2);
			return (0);
		}
	}
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
	newroom->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i++;
	newroom->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	newroom->y = ft_atoi(line + i);
	free(line);
	return (newroom);
}

t_path	*init_path(char *line)
{
	t_path		*newpath;
	int			score_pos;

	newpath = malloc(sizeof(t_path));
	if (!newpath)
		return (NULL);
	score_pos = (int)ft_strlchr(line, '-');
	newpath->door1 = ft_strsub(line, 0, score_pos);
	newpath->door2 = ft_strdup(line + score_pos + 1);
	free(line);
	return (newpath);
}
