/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   methods.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 05:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/27 17:33:52 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

t_room		*get_room_by_name(char *name, t_list *list)
{
	t_room		*tmp;
	int			done;

	done = 0;
	if (!list)
		return (NULL);
	while (list && !done)
	{
		tmp = (t_room *)list->data;
		done = ft_strequ(name, tmp->name);
		list = list->next;
	}
	return (done ? tmp : NULL);
}

void		drill(t_list *rooms, t_list *paths)
{
	t_list		*tmp_r;
	t_list		*tmp_p;
	t_room		*room;
	t_path		*path;

	tmp_r = rooms;
	while (tmp_r)
	{
		room = (t_room *)tmp_r->data;
		tmp_p = paths;
		while (tmp_p)
		{
			path = (t_path *)tmp_p->data;
			if (ft_strequ(path->door1, room->name))
				room->paths = ft_lst_push(room->paths,
						get_room_by_name(path->door2, rooms));
			if (ft_strequ(path->door2, room->name))
				room->paths = ft_lst_push(room->paths,
						get_room_by_name(path->door1, rooms));
			tmp_p = tmp_p->next;
		}
		tmp_r = tmp_r->next;
	}
}