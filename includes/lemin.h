/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 05:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/28 12:35:30 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define STARTROOM 	1
# define NORMAL 	2
# define ENDROOM	3

typedef struct		s_init
{
	int				flag;
	int				rooms_done;
	char			*line;
	int				read;
}					t_init;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				flag;
	int				busy;
	t_list			*paths;
}					t_room;

typedef struct		s_path
{
	char			*door1;
	char			*door2;
}					t_path;

typedef struct		s_ant
{
	t_room			*current;
}					t_ant;

void				drill(t_list *rooms, t_list *paths);
t_room				*get_room_by_name(char *name, t_list *list);
t_room				*get_room_by_flag(int flag, t_list *list);
t_path				*init_path(char *line);
t_room				*init_room(char *line, int room_flag);
int					is_command(char *line);
int					is_path(char *line, t_list *rooms);
int					is_room(char *line);
void				print_room(void *room);
void				print_room_paths(t_room *room);
int					test_pathfinding(void *room);

#endif
