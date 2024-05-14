/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/12 15:46:34 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_numeric(char *str)
{
	int	b;

	b = 1;
	while (*str != '\0')
	{
		if ((*str < '0') || (*str > '9'))
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
	char	string[] = "16844524d43";
	char	*p = string;

	char b = '0' + ft_str_is_numeric(p);
	write(1, &b, 1);
}
*/
