/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/20 12:17:34 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "lem-in.h"

void	out_rooms(t_list *first)
{
	t_list		*tmp;

	tmp = first;
	while (tmp)
	{
		ft_printf("%s %d %d\n", tmp->data->name, tmp->data->x, tmp->data->y);
		first = tmp;
		tmp = tmp->next;
		free(first->data->name);
		free(first->data);
		free(first);
	}
	return ;
}

void	out_tunnels(t_list *first)
{
	t_list		*tmp;

	tmp = first;
	while (tmp)
	{
		ft_printf("%d %d\n", tmp->data->x, tmp->data->y);
		first = tmp;
		tmp = tmp->next;
		free(first->data);
		free(first);
	}
	return ;
}

int		main(int ac, char **av)
{
	t_ant		*ants;
	t_list		*rooms;
	t_list		*tunnels;

	rooms = NULL;
	tunnels = NULL;
	antnum = init(&rooms, &tunnels);
	if (!antnum)
	{
		ft_putstr("ERROR");
	}
	ants = malloc(sizeof(t_ant) * antnum);
	ft_printf("%d\n", antnum);
	out_rooms(rooms);
	out_tunnels(tunnels);

	return (0);
}
