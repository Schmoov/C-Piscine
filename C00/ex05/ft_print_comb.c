/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:15:46 by parden            #+#    #+#             */
/*   Updated: 2024/02/08 19:06:01 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// Disgusting way to not end on ", " explain the if on last line
void	write_number(char a, char b, char c)
{
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, &c, 1);
	if (!(a == '7' && b == '8' && c == '9'))
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	n0;
	char	n1;
	char	n2;

	n0 = '0';
	n1 = '1';
	n2 = '2';
	while (n0 <= '7')
	{
		while (n1 <= '8')
		{
			while (n2 <= '9')
			{
				if (n0 < n1 && n1 < n2)
				{
					write_number(n0, n1, n2);
				}
			++n2;
			}
			++n1;
			n2 = n1;
		}
		++n0;
		n1 = n0;
	}
}
