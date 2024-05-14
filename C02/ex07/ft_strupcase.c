/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 15:18:23 by parden            #+#    #+#             */
/*   Updated: 2024/02/12 17:03:11 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) >= 'a' && *(str + i) <= 'z')
		{
			*(str + i) = *(str + i) - 32;
		}
		++i;
	}
	return (str);
}
/*
int	main()
{
	char	string[] = "asTd ;;; HfhH ))) fasdf";
	char	*p = string;
	char	*p2 = NULL;
	char	retour = '\n';

	write(1, p, 23);
	write(1, &retour, 1);
	p2 = ft_strupcase(p);
	write(1, p, 23);
	write(1, &retour, 1);
	write(1, p2, 23);
	write(1, &retour, 1);
}
*/
