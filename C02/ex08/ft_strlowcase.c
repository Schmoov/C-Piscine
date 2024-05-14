/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/12 20:56:37 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'A' && *(str + i) <= 'Z')
		{
			*(str + i) = *(str + i) + 32;
		}
		++i;
	}
	return (str);
}
/*

int	main()
{
	char	string[] = " alut, comment tu vas ? 42mots quarante-deux; cinquante+et+u ";
	char	*p = string;
	char	string2[] = "152256";
	char	*p2 = string2;

	ft_strcapitalize(p);
	write(1, p, 61);
	ft_strcapitalize(p2);
	write(1, p2, 6);
}*/
