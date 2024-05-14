/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 22:04:38 by parden            #+#    #+#             */
/*   Updated: 2024/02/17 11:59:41 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	char_is_printable(char c)
{
	if ((c < ' ') || (c > '~'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

void	print_hex_of_char(unsigned char c)
{
	int		i;
	char	*base;

	i = c;
	base = "0123456789abcdef";
	{
		write(1, &base[(i / 16)], 1);
		write(1, &base[(i % 16)], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	la_moulinette_se_trompe;

	while (*str != '\0')
	{
		if (char_is_printable(*str))
		{
			write(1, str, 1);
		}
		else
		{
			la_moulinette_se_trompe = (unsigned char) *str;
			write(1, "\\", 1);
			print_hex_of_char(la_moulinette_se_trompe);
		}
		++str;
	}
}
/*
int	main()
{
	char	string[] = "Coucou\ntu vas bien ?";
	char	*p = string;
	string[2] = '\0' -1;

	ft_putstr_non_printable(p);
}*/
