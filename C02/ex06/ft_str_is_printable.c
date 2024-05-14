/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/12 23:11:19 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_printable(char *str)
{
	int	b;

	b = 1;
	while (*str != '\0')
	{
		if ((*str < ' ') || (*str > '~'))
		{
			b = 0;
		}
		++str;
	}
	return (b);
}
/*
int	main()
{
	char	string[] = "";
	char	*p = string;

	char b = '0' + ft_str_is_printable(p);
	write(1, &b, 1);
}
*/
