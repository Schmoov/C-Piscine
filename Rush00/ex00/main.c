/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abergman <aron@bergman.re>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 16:19:55 by abergman          #+#    #+#             */
/*   Updated: 2024/02/11 21:46:44 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush01(int x, int y);

int	main(void)
{
	rush01(1, 5);
	return (0);
}

//BONUS
/*
void rush0X(int x, int y, char c);

int	is_space(char c)
{
	if ((c >= 9) && (c <= 13))
		return (1);
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	is_minus(char c)
{
	if (c == '-')
		return (1);
	else
		return (0);
}

int	str_to_int(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 0;
	result = 0;
	while (is_space(str[i]) || is_minus(str[i]))
	{
		if (is_minus(str[i]))
			sign++;
		i++;
	}
	while (str[i] && ((str[i] >= '0') && (str[i] <= '9')))
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	if ((sign % 2) == 0)
		return (result);
	else
		return (-result);
}
// str[i] – 48 to convert the character to numeric.
//ASCII value of character ‘5’ is 53, so 53 – 48 = 5

int	main(int argc, char **argv)
{
	int		a;
	int		b;
	char	c;

	a = 0;
	b = 0;
	if (! (argc == 4))
		return (-1);
	else
	{
		a = str_to_int(argv[1]);
		b = str_to_int(argv[2]);
		c = *argv[3];
	}
	rush0X (a, b, c);
	return (0);
}
*/
