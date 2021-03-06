/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 05:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/28 21:08:20 by abarbaro         ###   ########.fr       */
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

t_room		*get_room_by_flag(int flag, t_list *list)
{
	t_room		*tmp;
	int			done;

	done = 0;
	if (!list)
		return (NULL);
	while (list && !done)
	{
		tmp = (t_room *)list->data;
		done = tmp->flag == flag ? 1 : 0;
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

void		print_room_paths(t_room *room)
{
	t_list		*ls;
	t_room		*ptr;

	ft_printf("Room %s:\n", room->name);
	ls = room->paths;
	while (ls)
	{
		ptr = (t_room *)ls->data;
		ft_printf("->%s\n", ptr->name);
		ls = ls->next;
	}
}

int			find(void *room, int targetflag)
{
	t_room		*current;
	t_list		*testing;
	int			smallestpath;
	int			lastpath;

	current = (t_room *)room;
	if (current->flag == targetflag)
		return (0);
	if (current->busy)
		return (-1);
	current->busy = 1;
	smallestpath = 2147483647;
	testing = current->paths;
	while (testing)
	{
		if ((lastpath = find(testing->data, targetflag)) < smallestpath
														&& lastpath != -1)
			smallestpath = 1 + lastpath;
		testing = testing->next;
	}
	current->busy = 0;
	if (smallestpath == 2147483647)
		return (-1);
	else
		return (smallestpath);
}
