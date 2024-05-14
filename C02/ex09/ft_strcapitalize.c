/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/15 20:30:22 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		++i;
	}
	return (str);
}

int	is_lower(char c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	is_alphanum(char c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9') || is_lower(c))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

char	*ft_strcapitalize(char	*str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		while (!(is_alphanum(str[i])) && (str[i]))
		{
			++i;
		}
		if (is_lower(str[i]))
		{
			str[i] = str[i] - 32;
			++i;
		}
		while (is_alphanum(str[i]))
		{
			i++;
		}		
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
	write(1, "\n", 1);
	ft_strcapitalize(p2);
	write(1, p2, 6);
}*/
