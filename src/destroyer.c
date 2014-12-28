/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 20:03:42 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/28 21:08:25 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

void	destroy_room(void *data)
{
	t_room		*room;

	room = (t_room *)data;
	ft_strdel(&room->name);
	ft_lst_rec_free(room->paths);
	free(data);
	data = NULL;
}

void	destroy_path(void *data)
{
	t_path		*path;

	path = (t_path *)data;
	ft_strdel(&path->door1);
	ft_strdel(&path->door2);
	free(data);
	data = NULL;
}

void	destroy_everything(t_list *rooms, t_list *paths, int error)
{
	if (rooms)
	{
		ft_lst_foreach(rooms, destroy_room);
		ft_lst_rec_free(rooms);
	}
	if (paths)
	{
		ft_lst_foreach(paths, destroy_path);
		ft_lst_rec_free(paths);
	}
	if (error)
		ft_putstr("ERROR");
	exit (0);
}
