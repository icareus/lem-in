/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 06:09:22 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/20 17:14:52 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_room(char *line)
{
	while (*line && *line != ' ')
		line++;
	if (*line != ' ')
		return (0);
	line ++;
	if (*line == '-')
		line ++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != ' ')
		return (0);
	line ++;
	if (*line == '-')
		line ++;
	while (*line && ft_isdigit(*line))
		line++;
	if (*line != '\0')
		return (0);
	return (1);
}

int		is_path(char *line)
{
	if (ft_strchr('-', line))
		return (1);
	else
		return (0);
}

void	add_room(t_list **list, char *line)
{
	t_room		newroom;
	t_list		*tmp;
	int			i;

	i = 0;
	while (line[i] != ' ')
		i++;
	newroom.name = ft_memdup(line, i);
	while (line[i] == ' ')
		i++;
	newroom.x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	newroom.y = ft_atoi(line + i);
	tmp = *list;
	while (tmp != NULL)
		tmp = tmp->next;
	tmp = malloc(sizeof(t_list));
	tmp->next = NULL;
	tmp->data = ft_memdup(newroom, sizeof(t_room));
}

void	add_path(t_list **list, char *line)
{
	t_list		*tmp;
	t_path		newpath;
	int			score_pos;

	score_pos = (int)ft_strlchr('-');
	newpath.door1 = ft_memdup(line, score_pos);
	newpath.door2 = ft_strdup(line + score_pos);
	tmp = *list;
	while (tmp)
		tmp = tmp->next;
	tmp = malloc(sizeof(t_list));
	tmp->data = ft_memdup(newpath, sizeof(t_path));
}

int		is_command(line)
{
	if (line[0] == '#' && line[1] == '#')
	{
		if (ft_strequ("##START", line))
			return (STARTROOM);
		else if (ft_strequ("##END", line))
			return (ENDROOM);
		else
			return (NORMAL);
	}
	else
		return (-1);
}

void	init(t_list **rooms, t_list **paths)
{
	int		room_flag;
	int		read;
	int		rooms_done;
	char	*line;

	rooms_done = 0;
	while (read = get_next_line(0, &line))
	{
		if (read == -1)
		{
			ft_memdel(&line);
			return (-1);
		}
		else if (is_command(line) != -1)
			room_flag = is_command(line);
		else if (is_room(line) && !rooms_done)
			add_room(rooms, is_room(line));
		else if (is_path(line))
		{
			rooms_done = 1;
			add_path(paths, is_path(line));
		}
		else
			break ;
	}
	return (ant_number);
}