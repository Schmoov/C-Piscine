/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:23:56 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 19:50:26 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_triple_zero(char *str)
{
	if (str[0] == '0' && str[1] == '0' && str[2] == '0')
		return (1);
	return (0);
}

int	get_sub_1000_readable_length(char *str)
{
	int	l_sub;

	l_sub = 0;
	if (is_triple_zero(str))
		return (0);
	if (str[0] != '0')
		l_sub += 2;
	if (str[1] != '0' && str[1] != '1')
	{
		l_sub++;
		if (str[2] != '0')
			l_sub++;
	}
	else if (str[1] != '0' || str[2] != '0')
		l_sub++;
	return (l_sub);
}

int	get_readable_arr_length(char *str)
{
	int	length;
	int	i;

	length = 0;
	i = 0;
	while (str[i])
	{
		length += get_sub_1000_readable_length(&str[i]);
		i += 3;
		if (str[i] && !(is_triple_zero(&str[i - 3])))
			length++;
	}
	return (length);
}
