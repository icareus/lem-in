/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/28 14:59:28 by root              #+#    #+#             */
/*   Updated: 2014/12/28 19:12:54 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

int		can_move(t_ant *ant)
{
// ft_printf("can i move from %s ?", ant->room->name);
	t_list		*ls;
	t_room		*tmp;
	int			yes;
	int			may_move;

	if (ant->room->flag == ENDROOM)
{
// ft_putendl("Nope, am at the end.");
		return (0);
}
	yes = 1;
	may_move = 0;
	if (ant->did_turn)
		yes = 0;
	ls = ant->room->paths;
	while (yes && ls)
	{
// ft_putendl("can_move_loop");
		tmp = (t_room *)ls->data;
		if ((!tmp->has_ant && !(tmp->flag == STARTROOM) && tmp != ant->last)
			|| tmp->flag == ENDROOM)
		{
			may_move = 1;
			break ;
		}
		ls = ls->next;
	}
	return (yes && may_move);
}

void	play(t_ant *ant)
{
// ft_putendl("play_loop0");
	t_list		*ls;
	t_room		*tmp;
	t_room		*next;
	int			distance;
	int			result;

	distance = 2147483647;
	ls = ant->room->paths;
	while (ls)
	{
// ft_putendl("play_loop1");
		tmp = (t_room *)ls->data;
		if ((tmp->flag == ENDROOM || !tmp->has_ant) && tmp != ant->last)
		{
			result = find(tmp, ENDROOM);
			if (result < distance && result > -1)
			{
				distance = result;
				next = tmp;
			}
		}
		ls = ls->next;
	}
	if (distance < 2147483647)
		move(ant, next);
}

void	move(t_ant *ant, t_room *room)
{
	ant->room->has_ant = 0;
	ant->last = ant->room;
	ant->room = room;
	ant->room->has_ant = 1;
	ft_printf("L%s-%s ", ant->last->name, ant->room->name);
}

int		game_over(t_ant *ants, int antnum)
{
// ft_putendl("game_over ?");
	int		i;

	i = 0;
	while (i < antnum)
	{
		if (ants[i].room->flag != ENDROOM)
			return (0);
		i++;
	}
	return (1);
}

void	game_loop(t_ant *ants, int antnum)
{
	int		turn_ended;
	int		i;

	while (!game_over(ants, antnum))
	{
		turn_ended = 0;
// ft_putendl("game_loop1");
		reset_ants(ants, antnum);
		while (!turn_ended)
		{
// ft_putendl("game_loop2");
			turn_ended = 1;
			i = 0;
			while (i < antnum)
			{
				if (can_move(ants + i))
				{
// ft_putendl("game_loop3");
					play(ants + i);
					turn_ended = 0;
				}
				i++;
			}
			write(1, "\n", 1);
		}
	}
}