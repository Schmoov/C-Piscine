/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: parden <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:11:39 by parden            #+#    #+#             */
/*   Updated: 2024/02/21 15:35:20 by parden           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_intstr(int *str)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = str[i] + '0';
		write(1, &c, 1);
		++i;
	}
	write(1, "\n", 1);
}

int	valid_setup(int *board)
{
	int	i;
	int	j;

	i = 0;
	while (board[i + 1] != -1)
	{
		j = i + 1;
		while (board[j] != -1)
		{
			if (board[i] == board[j])
				return (0);
			if ((board[j] - j + i) == board[i]
				|| (board[j] + j - i) == board[i])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	solve(int *board, int step)
{
	int	i;
	int	count;

	count = 0;
	if (step == 10)
	{
		ft_put_intstr(board);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		board[step] = i;
		if (valid_setup(board))
			count += solve(board, step + 1);
		i++;
		board[step] = -1;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[11];
	int	i;

	i = 0;
	while (i < 11)
	{
		board[i] = -1;
		i++;
	}
	return (solve(board, 0));
}
/*
#include <stdio.h>
int main()
{
	int count;

	count = ft_ten_queens_puzzle();
	printf("on compte %d solutions\n", count);
}*/
