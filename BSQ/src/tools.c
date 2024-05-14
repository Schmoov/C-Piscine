/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:01:37 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 15:02:52 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*parse_first_line(char *file_path)
{
	int		fd;
	char	buff[256];
	int		ret;
	int		i;
	char	*first_line;

	i = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (NULL);
	ret = read(fd, buff, sizeof(buff));
	while (buff[i] != '\n')
		i++;
	first_line = malloc((sizeof(char) * i) + 1);
	if (!first_line)
		return (NULL);
	first_line[0] = '\0';
	ft_strncat(first_line, buff, i);
	close(fd);
	return (first_line);
}

char	*get_pattern(char *first_line)
{
	int		i;
	int		j;
	char	*pattern;

	j = 0;
	i = ft_strlen(first_line) - 1;
	pattern = malloc(sizeof(char) * 4);
	if (!pattern)
		return (NULL);
	while (j < 3)
	{
		pattern[j] = first_line[i];
		j++;
		i--;
	}
	pattern[j] = '\0';
	reverse_str(pattern);
	free(first_line);
	return (pattern);
}
