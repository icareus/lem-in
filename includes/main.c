/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/09 06:29:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/09 06:32:13 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		main(int ac, char **av)
{
	int		i;

	if (ac == 1)
		ft_putendl("Skel !");
	else
	{
		i = 0;
		while (++i < ac)
			ft_putendl(av[i]);
	}
	return (0);
}
