/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 11:13:25 by parden            #+#    #+#             */
/*   Updated: 2024/02/11 13:58:47 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	aff_char_array(char *arr, int length)
{
	int	i;

	i = 0;
	while (i < length)
	{
		write(1, arr + i, 1);
		++i;
	}
}

void	incr_char_array(char *arr, int length)
{
	int		first_incrable_pos;
	char	max_poss_value;

	first_incrable_pos = length - 1;
	max_poss_value = '9' + first_incrable_pos - length + 1;
	while (*(arr + first_incrable_pos) == max_poss_value)
	{
		--first_incrable_pos;
		--max_poss_value;
	}
	++*(arr + first_incrable_pos);
	while (first_incrable_pos < length)
	{
		++first_incrable_pos;
		*(arr + first_incrable_pos) = *(arr + first_incrable_pos - 1) + 1;
	}
}	

void	ft_print_combn(int n)
{
	char	chif[10];
	int		i;

	i = 0;
	while (i < n)
	{
		chif[i] = '0' + i;
		++i;
	}
	while (chif[0] != ('9' - n + 1))
	{
		aff_char_array(chif, n);
		write(1, ", ", 2);
		incr_char_array(chif, n);
	}
	aff_char_array(chif, n);
}
/*
int	main()
{
	ft_print_combn(5);
}
*/
