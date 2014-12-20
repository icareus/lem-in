/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putflt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 21:17:34 by abarbaro          #+#    #+#             */
/*   Updated: 2014/11/04 01:41:03 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putflt(float f)
{
	int		ret;
	int		intpart;
	int		i;

	ret = 0;
	i = 0;
	intpart = (int)f;
	ft_putnbr(intpart);
	ret = ft_nbrlen(intpart) + 8;
	write(1, ".", 1);
	f = ABS(f);
	while (i++ < 7)
	{
		f *= 10;
		ft_putchar(48 + ((int)f % 10));
	}
	return (ret);
}
