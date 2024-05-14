/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/12 16:26:12 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_uppercase(char *str)
{
	int	b;

	b = 1;
	while (*str != '\0')
	{
		if (*str < 'A' || *str > 'Z')
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
	char	string[] = "AZHFH";
	char	*p = string;

	char b = '0' + ft_str_is_uppercase(p);
	write(1, &b, 1);
}*/
