/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 22:58:49 by parden            #+#    #+#             */
/*   Updated: 2024/02/11 23:37:03 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	find_min(int *arr, int size)
{
	int	i;
	int	val_min;
	int	pos_min;

	i = 1;
	val_min = arr[0];
	pos_min = 0;
	while (i < size)
	{
		if (arr[i] < val_min)
		{
			val_min = arr[i];
			pos_min = i;
		}
		++i;
	}
	return (pos_min);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	pos_min;

	if (size > 1)
	{
		pos_min = find_min(tab, size);
		ft_swap(tab, tab + pos_min);
		ft_sort_int_tab(tab + 1, size - 1);
	}
}
/*
#include <stdio.h>
int     main()
{
        int tableau[] = {};
        ft_sort_int_tab(tableau, 0);
        int loop;

        for(loop = 0; loop < 0; loop++)
                printf("%d ", tableau[loop]);
}*/
