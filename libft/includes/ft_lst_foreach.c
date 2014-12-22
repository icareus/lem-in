/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_foreach.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 22:13:28 by lefebvre          #+#    #+#             */
/*   Updated: 2014/12/22 22:16:11 by lefebvre         ###   ########.fr       */
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