/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 13:35:12 by parden            #+#    #+#             */
/*   Updated: 2024/02/19 13:35:45 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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
/*
int	main()
{
	ft_putnbr(-2147483648);
}
*/
