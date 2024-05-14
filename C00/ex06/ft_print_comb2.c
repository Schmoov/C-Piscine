/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:15:46 by parden            #+#    #+#             */
/*   Updated: 2024/02/08 19:11:13 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Disgusting way to not end with ", " explains the if
void	write_number_couple(char a0, char a1, char b0, char b1)
{
	write(1, &a0, 1);
	write(1, &a1, 1);
	write(1, " ", 1);
	write(1, &b0, 1);
	write(1, &b1, 1);
	if (!(a0 == '9' && a1 == '8'))
	{
		write(1, ", ", 2);
	}
}

void	write_until_ab_99(char a, char b)
{
	char	a_bis;
	char	b_bis;

	if (!(b == '9'))
	{
		a_bis = a;
		b_bis = b + 1;
	}
	else
	{
		a_bis = a + 1;
		b_bis = '0';
	}
	while (a_bis <= '9')
	{
		while (b_bis <= '9')
		{
			write_number_couple(a, b, a_bis, b_bis);
			++b_bis;
		}
		b_bis = '0';
		++a_bis;
	}
}

void	ft_print_comb2(void)
{
	char	a;
	char	b;

	a = '0';
	b = '0';
	while (a <= '9')
	{
		while (b <= '9')
		{
			write_until_ab_99(a, b);
			++b;
		}
		b = '0';
		++a;
	}
}
