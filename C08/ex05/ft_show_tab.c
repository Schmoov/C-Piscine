/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 16:32:30 by parden            #+#    #+#             */
/*   Updated: 2024/02/28 16:45:47 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putdgt(int n)
{
	char	c;

	c = (n + 48);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	char	minus;

	minus = '-';
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
		ft_putnbr(nb);
	}
	else if (nb < 0)
	{
		write(1, &minus, 1);
		ft_putnbr(-nb);
	}
	else if ((nb / 10) == 0)
	{
		ft_putdgt(nb);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	print_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_string(par[i].str);
		ft_putnbr(par[i].size);
		write(1, "\n", 1);
		print_string(par[i].copy);
		i++;
	}
}
