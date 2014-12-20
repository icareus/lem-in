/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/20 20:03:32 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lem-in.h"

int		get_ant_number()
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
	// t_ant		*ants;
	t_list		*rooms;
	t_list		*tunnels;
	int			antnum;

	rooms = NULL;
	tunnels = NULL;
	antnum = get_ant_number();
	init(&rooms, &tunnels);
	if (!antnum)
	{
		ft_putstr("ERROR");
	}
	// ants = malloc(sizeof(t_ant) * antnum);
	ft_printf("%d\n", antnum);
	out_rooms(rooms);
	out_tunnels(tunnels);

	return (0);
}
