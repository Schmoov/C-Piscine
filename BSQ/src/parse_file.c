/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpruvot <mpruvot@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 20:12:39 by mpruvot           #+#    #+#             */
/*   Updated: 2024/02/28 12:11:18 by mpruvot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "bsq.h"

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i])
			i++;
	while (src[j] && (j < nb))
	{
			dest[i] = src[j];
			i++;
			j++;
	}
	dest[i] = '\0';
	return (dest);
}

// Get the full leght of a given file
int	len_file(char *file_path)
{
	int		fd;
	int		len;
	char	buff[256];
	int		ret;

	len = 0;
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buff, sizeof(buff));
	while (ret > 0)
	{
		len += ret;
		ret = read(fd, buff, sizeof(buff));
	}
	close(fd);
	if (len > 0)
		return (len);
	return (-1);
}

// convert a file into a (char *)
char	*convert_file(char *file_path)
{
	char	*str_file;
	int		fd;
	int		ret;
	char	buff[257];

	str_file = malloc(sizeof(char) * (len_file(file_path) + 1));
	if (!str_file)
		return (NULL);
	fd = open(file_path, O_RDONLY);
	if (fd == -1)
	{
		free(str_file);
		return (NULL);
	}
	*str_file = '\0';
	ret = read(fd, buff, 256);
	while (ret > 0)
	{
		buff[ret] = '\0';
		ft_strncat(str_file, buff, ret);
		ret = read(fd, buff, 256);
	}
	close(fd);
	return (str_file);
}
