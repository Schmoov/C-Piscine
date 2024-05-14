/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 10:13:05 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 18:06:42 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"


void	read_input(int fd)
{
	char	buff[1000];
	int		lines;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	lines = 0;
	while (ret != -1)
	{
		ret = read(0, buff, 1000);
		if (lines == 0)
			lines = get_line_number(buff);
		else
			i++;
		write(fd, buff, ret);
		if (i == lines)
			break ;
	}
	buff[ret] = '\0';
	close(fd);
}
