/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 11:37:15 by parden            #+#    #+#             */
/*   Updated: 2024/02/20 13:01:13 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_pair {
	int	n1;
	int	n2;

}	t_pair;

t_pair	doublefibo(int index)
{
	t_pair	res;
	t_pair	fibon_1;

	if (index == 0)
	{
		res.n1 = 0;
		res.n2 = 0;
		return (res);
	}
	if (index == 1)
	{
		res.n1 = 1;
		res.n2 = 0;
		return (res);
	}
	fibon_1 = doublefibo(index - 1);
	res.n1 = fibon_1.n1 + fibon_1.n2;
	res.n2 = fibon_1.n1;
	return (res);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	return (doublefibo(index).n1);
}
/*
#include <stdio.h>
#include <stdlib.h>
int	main(int c, char **v)
{
	printf("%d\n", ft_fibonacci(atoi(v[1])));
	c++;
}*/
