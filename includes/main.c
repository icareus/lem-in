/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/25 04:28:27 by lefebvre         ###   ########.fr       */
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
		{
			*rooms = ft_lst_push(*rooms, init_room(line, room_flag));
			room_flag = NORMAL;
		}
		else if (is_path(line) && (rooms_done = 1))
			*paths = ft_lst_push(*paths, init_path(line));
		else
			break ;
	}
	return (0);
}

void	print_room(void *room)
{
	t_room		*tmp;

	tmp = (t_room *)room;
	if (tmp->flag == STARTROOM)
		ft_printf("##START\n");
	else if (tmp->flag == ENDROOM)
		ft_printf("##END\n");
	ft_printf("%s %d %d\n", tmp->name,
							tmp->x, tmp->y);
	free(tmp->name);
	free(tmp);
}

void	print_path(void *tunnel)
{
	t_path		*path;

	path = (t_path *)tunnel;
	ft_printf("%s-%s\n", path->door1, path->door2);
	// free(path->door1);
	// free(path->door2);
}

int		main(void)
{
	t_list		*rooms;
	t_list		*paths;
	int			antnum;
	//t_ant		*ants;

	rooms = NULL;
	paths = NULL;
	antnum = get_ant_number();
	if (!antnum)
		ft_putstr("ERROR");
	else
	{
		init(&rooms, &paths);
		// ants = malloc(sizeof(t_ant) * antnum);
		ft_printf("%d\n", antnum);
		ft_lst_foreach(rooms, print_room);
		ft_lst_foreach(paths, print_path);
	}
	return (0);
}
