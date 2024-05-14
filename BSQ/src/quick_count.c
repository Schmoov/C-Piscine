/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 12:06:55 by parden            #+#    #+#             */
/*   Updated: 2024/02/28 12:26:19 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	nb_obs_square(int **mat, int xi, int yi, int l)
{
	int	res;

	res = mat[yi + l - 1][xi + l - 1];
	if (yi)
		res -= mat[yi - 1][xi + l - 1];
	if (xi)
		res -= mat[yi + l - 1][xi - 1];
	if (xi && yi)
		res += mat[yi - 1][xi - 1];
	return (res);
}
