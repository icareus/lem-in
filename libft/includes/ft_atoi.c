/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbaro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/02 22:14:45 by abarbaro          #+#    #+#             */
/*   Updated: 2014/10/02 13:46:05 by abarbaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_count_spaces_start(const char *str)
{
	int i;

	i = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
	{
		i++;
	}
	return (i);
}

int			ft_atoi(const char *str)
{
	int	i;
	int mult;
	int total;

	i = ft_count_spaces_start(str);
	mult = 1;
	total = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			mult = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		total *= 10;
		total += (str[i] - '0');
		i++;
	}
	return (mult * total);
}
