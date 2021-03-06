/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <abarbaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 22:13:28 by abarbaro          #+#    #+#             */
/*   Updated: 2014/12/25 05:24:11 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_foreach(t_list *lst, void (*f)())
{
	t_list		*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->data);
		tmp = tmp->next;
	}
}
