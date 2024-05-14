/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <aron@bergman.re>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 12:22:39 by abergman          #+#    #+#             */
/*   Updated: 2024/02/11 21:49:13 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putline(char start, char middle, char end, int length_line)
{
	int	length_x;

	length_x = length_line;
	ft_putchar(start);
	while (length_x > 2)
	{
		ft_putchar(middle);
		length_x = length_x - 1;
	}
	if (length_x == 2)
	{
		ft_putchar(end);
	}
	ft_putchar('\n');
}

void	rush01(int x, int y)
{
	int	length_y;
	int	length_x;

	length_y = y;
	length_x = x;
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (length_y >= 1)
	{
		if (length_y == y)
		{
			ft_putline('/', '*', '\\', length_x);
		}
		else if (length_y == 1)
		{
			ft_putline('\\', '*', '/', length_x);
		}
		else
		{
			ft_putline('*', ' ', '*', length_x);
		}
		length_y = length_y - 1;
	}
}
/*

int	char_to_subject(char c)
{
	int	nb_subject;

	nb_subject = c - 'a' + 1;
	nb_subject = nb_subject % 5;
	return (nb_subject);
}

void	rush0X(int x, int y, char c)
{
	int		length_y;
	int		length_x;
	int		nb_sub;
	char	table_char[] = {'o','o','o','o','-','|','/','\\','\\','/','*'
	LINEBREAKFORNORM, '*','A','A','C','C','B','B','A','C','A','C'
	LINEBREAKFORNORM,'B','B','A','C','C','A','B','B'};

	length_y = y;
	length_x = x;
	nb_sub = char_to_subject(c);
	//table char {ul,ur,dl,dr,he,ve,....}
	//4 corners, horizontal edge, vertical edge
	if (x <= 0 || y <= 0)
	{
		return ;
	}
	while (length_y >= 1)
	{
		if (length_y == y)
		{
			ft_putline(table_char[6*nb_sub], table_char
			LINEBREAK[4+6*nb_sub],table_char[1+6*nb_sub], length_x);
		}
		else if (length_y == 1)
		{
			ft_putline(table_char[2+6*nb_sub], table_char
			LINEBREAK[4+6*nb_sub], table_char[3+6*nb_sub], length_x);
		}
		else
		{
			ft_putline(table_char[5+6*nb_sub], ' ', table_char[5+6*nb_sub], length_x);
		}
		length_y = length_y - 1;
	}
}*/
