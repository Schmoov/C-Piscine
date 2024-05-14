/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_readable_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:23:56 by parden            #+#    #+#             */
/*   Updated: 2024/02/25 19:42:38 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	burn_everything_and_run(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
}

int	ins_magnitude(char **res, char *str, int i_res, int i_str)
{
	int	l_mag;
	int	i;

	l_mag = ft_strlen(&str[i_str]) + 1;
	res[i_res] = (char *)malloc((l_mag + 1) * sizeof(char));
	if (res[i_res] == NULL)
		return (-1);
	res[i_res][0] = '1';
	i = 1;
	while (i < l_mag)
		res[i_res][i++] = '0';
	res[i_res][i] = 0;
	return (i_res);
}

char	**init_str_to_readable_arr(char	*str)
{
	char	**res;

	l_res = get_readable_arr_length(str);
	res = (char **)malloc((l_res + 1) * sizeof(char *));
	return (res);
}

char	**str_to_readable_arr(char **res, char	*str, int i_str, int l_res)
{
	int	i_res;

	i_res = 0;
	while (i_res < l_res)
	{
		i_res = ins_readable_sub_1000(res, str, i_res, i_str);
		if (i_res == -1)
		{
			burn_everything_and_run(res);
			return (NULL);
		}
		i_str += 3;
		if (str[i_str] && !(is_triple_zero(&str[i_str - 3])))
		{
			i_res = ins_magnitude(res, str, i_res, i_str);
			if (i_res == -1)
			{
				burn_everything_and_run(res);
				return (NULL);
			}
			i_res++;
		}
	}
	res[i_res] = NULL;
	return (res);
}
