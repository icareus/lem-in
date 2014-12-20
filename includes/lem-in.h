/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/20 05:37:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/20 17:16:07 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM-IM_H
# define LEM-IM_H

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
	char	*name;
	int		x;
	int		y;
}					t_room;

typedef struct		s_path
{
	char	*door1;
	char	*door2;
}					t_path;

int					init(t_list **rooms, t_list **tunnels);


#endif