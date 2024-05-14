/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:54:52 by parden            #+#    #+#             */
/*   Updated: 2024/02/22 22:28:32 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(char **a, char **b)
{
	char	*swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && (s1[i] == s2[i]))
	{
		i++;
	}
	if (s1[i] == s2[i])
		return (0);
	else if (s1[i] > s2[i])
		return (1);
	else
		return (-1);
}

int	find_min(char **arr, int size)
{
	int		i;
	char	*val_min;
	int		pos_min;

	i = 1;
	val_min = arr[0];
	pos_min = 0;
	while (i < size)
	{
		if (ft_strcmp(val_min, arr[i]) > 0)
		{
			val_min = arr[i];
			pos_min = i;
		}
		++i;
	}
	return (pos_min);
}

void	ft_sort_charar_tab(char **tab, int size)
{
	int	pos_min;

	if (size > 1)
	{
		pos_min = find_min(tab, size);
		ft_swap(tab, tab + pos_min);
		ft_sort_charar_tab(tab + 1, size - 1);
	}
}

int	main(int c, char **v)
{
	int	i;
	int	j;

	i = 1;
	ft_sort_charar_tab(&v[1], c - 1);
	while (i < c)
	{
		j = 0;
		while (v[i][j])
			write(1, &v[i][j++], 1);
		write(1, "\n", 1);
		i++;
	}
}
