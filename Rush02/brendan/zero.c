/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zero.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvictoir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:36:13 by bvictoir          #+#    #+#             */
/*   Updated: 2024/02/25 21:36:28 by bvictoir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	pre_zero(char *str)
{
	int len = ft_strlen(str);
    int remainder = len % 3;
	int i;

	i = 0;
    if (remainder > 0) {
        int zerosToAdd = 3 - remainder;

        char *newStr;
		newStr = (char *)malloc((len + zerosToAdd + 1) * sizeof(char));
		if (!newStr)
			return ;

		while (i < zerosToAdd)
			newStr[i++] = '0';
        ft_strcpy(newStr + zerosToAdd, str);
        ft_strcpy(str, newStr);
        free(newStr);
    }
}

