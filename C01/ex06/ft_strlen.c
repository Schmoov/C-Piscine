/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:40:20 by parden            #+#    #+#             */
/*   Updated: 2024/02/11 16:50:44 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
int	ft_strlen(char *str)
{
	int	length;

	length = 0;
	while (*str != '\0')
	{
		++length;
		++str;
	}
	return (length);
}
/*
int	main()
{
	char	*string;
	char	l;

	string = "";
	l = '0' + ft_strlen(string);
	write(1, &l, 1);
}*/
