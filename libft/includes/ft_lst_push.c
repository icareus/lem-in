/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 19:24:47 by lefebvre          #+#    #+#             */
/*   Updated: 2014/12/22 20:24:30 by lefebvre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lst_push(t_list *first, void *item)
{
	t_list		*tmp;

	if (!first)
	{
		first = malloc(sizeof(t_list));
		first->data = item;
		first->next = NULL;
	}
	else
	{
		tmp = first;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = malloc(sizeof(t_list));
		tmp->next->data = item;
		tmp->next->next = NULL;
	}
	return (first);
}