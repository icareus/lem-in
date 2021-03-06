/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 15:01:01 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/28 21:24:05 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

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
