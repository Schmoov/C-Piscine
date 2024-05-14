/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/15 22:39:57 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	b;

	b = 1;
	while (*str != '\0')
	{
		if (*str < 'a' || *str > 'z')
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
	char	string[] = "asTdfasdf";
	char	*p = string;

	char b = '0' + ft_str_is_lowercase(p);
	write(1, &b, 1);
}*/
