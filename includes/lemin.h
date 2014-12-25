/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 05:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/25 03:18:20 by lefebvre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

# define STARTROOM 	0
# define NORMAL 	1
# define ENDROOM	2
# define UNKNOWN	3

typedef struct		s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

typedef struct		s_room
{
	char			*name;
	int				x;
	int				y;
	int				flag;
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

t_path				*init_path(char *line);
t_room				*init_room(char *line, int room_flag);
int					is_command(char *line);
int					is_path(char *line);
int					is_room(char *line);

#endif
