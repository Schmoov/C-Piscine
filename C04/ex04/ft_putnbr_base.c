/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:25:51 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 12:09:40 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_valid_base(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		if (str[i] == '+' || str[i] == '-' || str[i] < ' ' || str[i] > '~')
			return (0);
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

void	ft_long_putnbr_base(long int nbr, char *base)
{
	int	l_base;

	l_base = is_valid_base(base);
	if (!l_base)
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		ft_long_putnbr_base(-nbr, base);
	}
	else if (nbr >= l_base)
	{
		ft_long_putnbr_base((nbr / l_base), base);
		write(1, &base[nbr % l_base], 1);
	}
	else
		write(1, &base[nbr % l_base], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	lnbr;

	lnbr = (long int) nbr;
	ft_long_putnbr_base(lnbr, base);
}
/*
#include <stdlib.h>
int	main(int c, char **v)
{
	ft_putnbr_base(atoi(v[1]), v[2]);
	c++;
}*/
