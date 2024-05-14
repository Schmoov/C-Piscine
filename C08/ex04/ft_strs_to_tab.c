/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:38:08 by parden            #+#    #+#             */
/*   Updated: 2024/02/28 16:47:43 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	long int	l_src;
	long int	i;
	char		*dup;

	l_src = 0;
	while (src[l_src])
		l_src++;
	dup = (char *)malloc((l_src + 1) * sizeof(char));
	if (dup == 0)
	{
		free(dup);
		return (0);
	}
	i = 0;
	while (src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

void	burn_all(t_stock_str *res)
{
	int	i;

	i = 0;
	while (res[i].copy)
		free(res[i++].copy);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*res;
	int			i;

	i = 0;
	res = (t_stock_str *)malloc((1 + ac) * sizeof(t_stock_str));
	if (res == NULL)
	{
		free(res);
		return (NULL);
	}
	while (i < ac)
	{
		res[i].size = ft_strlen(av[i]);
		res[i].str = av[i];
		res[i].copy = ft_strdup(av[i]);
		if (res[i].copy == NULL)
		{
			burn_all(res);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i].str = NULL;
	return (res);
}
