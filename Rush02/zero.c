/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:36:13 by bvictoir          #+#    #+#             */
/*   Updated: 2024/02/25 23:17:33 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	pre_zero(char *str)
{
	int		len;
	int		remainder;
	int		i;
	int		zero_to_add;
	char	*new_str;

	len = ft_strlen(str);
	remainder = len % 3;
	i = 0;
	if (remainder > 0)
	{
		zero_to_add = 3 - remainder;
		new_str = (char *)malloc((len + zero_to_add + 1) * sizeof(char));
		if (!new_str)
			return ;
		while (i < zero_to_add)
			newStr[i++] = '0';
		ft_strcpy(newStr + zero_to_tdd, str);
		ft_strcpy(str, new_str);
		free(newStr);
	}
}
