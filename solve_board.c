/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 16:52:10 by dopeyrat          #+#    #+#             */
/*   Updated: 2022/09/17 20:18:36 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	get_coords_next(int **board, int *i, int *j, int size)
{
	while (*i < size)
	{
		*j = 0;
		while (*j < size)
		{
			if (board[*i][*j] == 0)
				return ;
			(*j)++;
		}
		(*i)++;
	}
}

int	check_prev(int **board, int x, int y)
{
	int	i;
	int	j;

	i = x - 1;
	j = y;
	while (i >= 0)
	{
		if (board[i][j] == board[x][y])
			return (-1);
		i--;
	}
	i = x;
	j = y - 1;
	while (j >= 0)
	{
		if (board[i][j] == board[x][y])
			return (-1);
		j--;
	}
	return (0);
}

int	last_tile(int **board, char *str, int size, int *i)
{
	int	temp;

	temp = check_solved(board, str, size);
	if (temp)
		return (display_board(board, size));
	board[i[0]][i[1]] = 0;
	return (-1);
}

int	solve_board(int **board, int size, char *str)
{
	int	i[2];
	int	temp;

	i[0] = 0;
	i[1] = 0;
	get_coords_next(board, &i[0], &i[1], size);
	board[i[0]][i[1]]++;
	while (board[i[0]][i[1]] <= size)
	{
		while (check_prev(board, i[0], i[1]) && board[i[0]][i[1]] <= size)
			board[i[0]][i[1]]++;
		if (board[i[0]][i[1]] > size)
			break ;
		if (i[0] == size - 1 && i[1] == size - 1)
			return (last_tile(board, str, size, i));
		else
		{
			temp = solve_board(board, size, str);
			if (temp == 0)
				return (0);
			board[i[0]][i[1]]++;
		}
	}
	board[i[0]][i[1]] = 0;
	return (-1);
}
