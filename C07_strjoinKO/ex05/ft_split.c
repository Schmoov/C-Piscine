/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 20:02:04 by parden            #+#    #+#             */
/*   Updated: 2024/02/29 14:01:45 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_char_in_str(char c, char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (!str[0])
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	word_l(char *str, char *charset)
{
	int	i;

	i = 0;
	while ((!is_char_in_str(str[i], charset)) && str[i])
		i++;
	return (i);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (is_char_in_str(str[i], charset))
			i++;
		if (str[i])
			count++;
		while ((!is_char_in_str(str[i], charset)) && str[i])
			i++;
	}
	return (count);
}

int	insert_word(char *res, char *str, int i_str, char *charset)
{
	int	i;

	i = 0;
	while (!(is_char_in_str(str[i_str + i], charset)) && str[i_str + i])
	{
		res[i] = str[i_str + i];
		i++;
	}
	res[i] = 0;
	i_str += i;
	while (is_char_in_str(str[i_str], charset) && str[i_str])
		i_str++;
	return (i_str);
}

char	**ft_split(char *str, char *charset)
{
	int		word_count;
	char	**res;
	int		i_res;
	int		i_str;

	word_count = count_words(str, charset);
	res = (char **)malloc((word_count + 1) * sizeof(char *));
	if (res == NULL || str == NULL)
		return (NULL);
	res[word_count] = NULL;
	i_res = 0;
	i_str = 0;
	while (is_char_in_str(str[i_str], charset) && str[i_str])
		i_str++;
	while (i_res < word_count)
	{
		res[i_res] = (char *)malloc((1 + word_l(&str[i_str], charset)));
		if (res[i_res] == NULL)
			return (NULL);
		i_str = insert_word(res[i_res], str, i_str, charset);
		i_res++;
	}
	return (res);
}
/*
#include <stdio.h>
int	main()
{
	char **res = ft_split("sssss", "sdfsdf");
	int	i = 0;
//	c++;
	if (!res)
		return (0);
	while (res[i])
		printf("%s\n", res[i++]);
}*/
