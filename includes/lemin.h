/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 05:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/28 19:31:36 by root             ###   ########.fr       */
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
	int				has_ant;
	t_list			*paths;
}					t_room;

typedef struct		s_path
{
	char			*door1;
	char			*door2;
}					t_path;

typedef struct		s_ant
{
	int				id;
	t_room			*room;
	t_room			*last;
	int				did_turn;
}					t_ant;

void				drill(t_list *rooms, t_list *paths);
int					find(void *room, int flag);
void				game_loop(t_ant *ants, int antnum);
t_room				*get_room_by_name(char *name, t_list *list);
t_room				*get_room_by_flag(int flag, t_list *list);
t_ant				*init_ants(int antnum, t_list *rooms);
t_path				*init_path(char *line);
t_room				*init_room(char *line, int room_flag);
int					is_command(char *line);
int					is_path(char *line, t_list *rooms);
int					is_room(char *line);
void				move(t_ant *ant, t_room *room);
void				print_room(void *room);
void				print_room_paths(t_room *room);
void				reset_ants(t_ant *ants, int antnum);

#endif
