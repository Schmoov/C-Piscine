/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buff_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 22:49:01 by bvictoir          #+#    #+#             */
/*   Updated: 2024/02/25 23:01:58 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft.h"

int	buff_size(void)
{
	char	buff[1];
	int		b_size;
	int		r_size;
	int		dict;

	b_size = 1;
	r_size = b_size;
	dict = open("numbers.dict", O_RDONLY);
	while (read(dict, buff, 1))
		r_size++;
	close(dict);
	return (r_size);
}
