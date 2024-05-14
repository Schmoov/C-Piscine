/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 16:29:40 by parden            #+#    #+#             */
/*   Updated: 2024/02/11 16:39:20 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while ((*str) != '\0')
	{
		write(1, str, 1);
		++str;
	}
}
/*
int	main()
{
	char	*string;

	string = "Goodbye cruel world";
	ft_putstr(string);
}*/
