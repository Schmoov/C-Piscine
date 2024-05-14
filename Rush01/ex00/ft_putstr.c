/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsanterr <rsanterr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:05:35 by rsanterr          #+#    #+#             */
/*   Updated: 2024/02/13 19:16:57 by rsanterr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putstr(char *str)
{
	if (str == NULL)
		return ;
	while (*str != 0)
	{
		write(1, str, 1);
		++str;
	}
	return ;
}

/*
int	main(void)
{
	ft_putstr("norminette\n\nc'est trop d'la balle");
	ft_putstr("\nZ");
	ft_putstr("");
	ft_putstr(NULL);
	ft_putstr("\nI <3 norminette ");
	
}
*/
