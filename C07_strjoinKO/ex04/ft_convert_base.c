/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:27:32 by parden            #+#    #+#             */
/*   Updated: 2024/02/27 19:59:08 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_valid_base(char *str);

int	ft_atoi_base(char *str, char *base);

int	get_length_base_to(long nbr_as_int, char *base_to)
{
	int	l_base;
	int	res;

	l_base = is_valid_base(base_to);
	res = 1;
	if (nbr_as_int < 0)
		res++;
	while (nbr_as_int / l_base)
	{
		res++;
		nbr_as_int /= l_base;
	}
	return (res);
}

int	ft_strlen(char *str)
{
	int	l;

	l = 0;
	while (str[l])
		l++;
	return (l);
}

void	fill_res(long nbr_as_int, char *res, int l_res, char *base_to)
{
	int	i;
	int	l_base_to;

	l_base_to = ft_strlen(base_to);
	i = 0;
	if (nbr_as_int < 0)
	{
		res[i++] = '-';
		nbr_as_int = -nbr_as_int;
	}
	while (i < l_res)
	{
		res[l_res - 1] = base_to[nbr_as_int % l_base_to];
		nbr_as_int /= l_base_to;
		l_res--;
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_as_int;
	int		l_res;
	char	*res;
	int		l_base_to;

	l_base_to = is_valid_base(base_from);
	if (!l_base_to)
		return (NULL);
	l_base_to = is_valid_base(base_to);
	if (!l_base_to)
		return (NULL);
	nbr_as_int = ft_atoi_base(nbr, base_from);
	l_res = get_length_base_to(nbr_as_int, base_to);
	res = (char *)malloc(l_res * sizeof(char));
	fill_res(nbr_as_int, res, l_res, base_to);
	return (res);
}

#include <unistd.h>
int	main(int c, char **v)
{
	char *res = ft_convert_base(v[1], v[2], v[3]);

	printf("%s",res);
	c++;
}
