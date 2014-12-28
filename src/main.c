/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/28 21:18:44 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <lemin.h>

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
		return (0);
	}
	while (*line == '#')
	{
		free (line);
		read = get_next_line(0, &line);
		if (read == -1)
		{
			ft_memdel((void **)&line);
			return (0);
		}
	}
	ant_number = atoi(line);
	ft_memdel((void **)&line);
	return (ant_number);
}

int		init(t_list **rooms, t_list **paths)
{
	t_init		vars;

	vars.rooms_done = 0;
	vars.flag = NORMAL;
	while ((vars.read = get_next_line(0, &vars.line)))
	{
		if (vars.read == -1)
			ft_memdel((void **)&vars.line);
		else if (is_command(vars.line))
			vars.flag = vars.flag == NORMAL ? is_command(vars.line) : vars.flag;
		else if (is_room(vars.line) && !vars.rooms_done)
		{
			*rooms = ft_lst_push(*rooms, init_room(vars.line, vars.flag));
			vars.flag = NORMAL;
		}
		else if (is_path(vars.line, *rooms) && (vars.rooms_done = 1))
			*paths = ft_lst_push(*paths, init_path(vars.line));
		else
			break ;
	}
	free(vars.line);
	return (0);
}

void	print_room(void *room)
{
	t_room		*tmp;

	if (!room)
	{
		write(1, "\n", 1);
		return ;
	}
	tmp = (t_room *)room;
	if (tmp->flag == STARTROOM)
		ft_printf("##start\n");
	else if (tmp->flag == ENDROOM)
		ft_printf("##end\n");
	ft_printf("%s %d %d\n", tmp->name,
							tmp->x, tmp->y);
}

void	print_path(void *tunnel)
{
	t_path		*path;

	path = (t_path *)tunnel;
	ft_printf("%s-%s\n", path->door1, path->door2);
}

int		main(void)
{
	t_list		*rooms;
	t_list		*paths;
	int			antnum;
	t_ant		*ants;

	rooms = NULL;
	paths = NULL;
	antnum = get_ant_number();
	if (!antnum)
		ft_putstr("ERROR");
	else
	{
		init(&rooms, &paths);
		if (!rooms || !paths)
			destroy_everything(rooms, paths, 1);
		ants = init_ants(antnum, rooms);
		ft_printf("%d\n", antnum);
		ft_lst_foreach(rooms, print_room);
		ft_lst_foreach(paths, print_path);
		write(1, "\n", 1);
		drill(rooms, paths);
		valid_or_die(rooms, paths);
		game_loop(ants, antnum, rooms, paths);
	}
	return (0);
}
