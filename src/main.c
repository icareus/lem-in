/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/27 13:04:49 by root             ###   ########.fr       */
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
	ant_number = atoi(line);
	if (!ant_number)
		return (0);
	ft_memdel((void **)&line);
	return (ant_number);
}

int		init(t_list **rooms, t_list **paths)
{
	t_init		vars;

	vars.rooms_done = 0;
	while ((vars.read = get_next_line(0, &vars.line)))
	{
		if (vars.read == -1)
			ft_memdel((void **)&vars.line);
		else
		{
			vars.flag = vars.flag == NORMAL ? is_command(vars.line) : vars.flag;
			if (is_room(vars.line) && !vars.rooms_done)
			{
				*rooms = ft_lst_push(*rooms, init_room(vars.line,
													vars.flag));
				vars.flag = NORMAL;
			}
			else if (is_path(vars.line) && (vars.rooms_done = 1))
				*paths = ft_lst_push(*paths, init_path(vars.line));
		}
		free(vars.line);
	}
	free(vars.line);
	return (0);
}

void	print_room(void *room)
{
	t_room		*tmp;

	tmp = (t_room *)room;
	if (tmp->flag == STARTROOM)
		ft_printf("##start\n");
	else if (tmp->flag == ENDROOM)
		ft_printf("##end\n");
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
	free(path->door1);
	path->door1 = NULL;
	free(path->door2);
	path->door2 = NULL;
}

int		main(void)
{
	t_list		*rooms;
	t_list		*paths;
	int			antnum;

	rooms = NULL;
	paths = NULL;
	antnum = get_ant_number();
	if (!antnum)
		ft_putstr("ERROR");
	else
	{
		init(&rooms, &paths);
		ft_printf("%d\n", antnum);
		ft_lst_foreach(rooms, print_room);
		ft_lst_foreach(paths, print_path);
	}
	return (0);
}
