/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/20 21:40:22 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <libft.h>
#include "lemin.h"

int		get_ant_number(void)
{
	char	*line;
	int		ant_number;
	int		read;

	line = NULL;
	read = get_next_line(0, &line);
	if (read == -1)
	{
		ft_memdel((void **)&line);
		return (-1);
	}
	ant_number = atoi(line);
	if (!ant_number)
		return (-1);
	ft_memdel((void **)&line);
	return (ant_number);
}

int		init(t_list **rooms, t_list **paths)
{
	int		room_flag;
	int		read;
	int		rooms_done;
	char	*line;

	rooms_done = 0;
	while ((read = get_next_line(0, &line)))
	{
		if (read == -1)
		{
			ft_memdel((void **)&line);
			return (-1);
		}
		else if (is_command(line) != -1)
			room_flag = is_command(line);
		else if (is_room(line) && !rooms_done)
			add_room(rooms, line, room_flag);
		else if (is_path(line) && (rooms_done = 1))
			add_path(paths, line);
		else
			break ;
	}
	return (0);
}

void	out_rooms(t_list *first)
{
	t_list		*tmp;
	t_room		*tmp_room;

	tmp = first;
	while (tmp)
	{
		tmp_room = (t_room *)tmp->data;
		ft_printf("%s %d %d\n", tmp_room->name,
								tmp_room->x, tmp_room->y);
		first = tmp;
		tmp_room = (t_room *)tmp->data;
		tmp = tmp->next;
		free(tmp_room->name);
		free(first->data);
		free(first);
	}
	return ;
}

void	out_tunnels(t_list *first)
{
	t_list		*tmp;
	t_path		*tmp_path;

	tmp = first;
	while (tmp)
	{
		tmp_path = (t_path *)tmp->data;
		ft_printf("%s %s\n", tmp_path->door1, tmp_path->door2);
		first = tmp;
		tmp_path = (t_path *)tmp->data;
		tmp = tmp->next;
		free(tmp_path->door1);
		free(tmp_path->door2);
		free(first->data);
		free(first);
	}
	return ;
}

int		main(void)
{
	t_list		*rooms;
	t_list		*tunnels;
	int			antnum;
	//t_ant		*ants;

	rooms = NULL;
	tunnels = NULL;
	antnum = get_ant_number();
	if (!antnum)
		ft_putstr("ERROR");
	else
	{
		init(&rooms, &tunnels);
		// ants = malloc(sizeof(t_ant) * antnum);
		ft_printf("%d\n", antnum);
		out_rooms(rooms);
		out_tunnels(tunnels);
	}
	return (0);
}
