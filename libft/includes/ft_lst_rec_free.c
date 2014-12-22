/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_rec_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lefebvre <lefebvre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 19:49:45 by lefebvre          #+#    #+#             */
/*   Updated: 2014/12/22 20:38:07 by lefebvre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_rec_free(t_list *first)
{
	if (first)
	{
		ft_lst_rec_free(first->next);
		free(first);
	}
}