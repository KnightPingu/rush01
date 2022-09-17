/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:48:47 by dopeyrat          #+#    #+#             */
/*   Updated: 2022/09/17 20:25:59 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	display_board(int **board, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size)
	{
		i = 0;
		while (i < size)
		{
			ft_putchar(board[i][j] + 48);
			if (i < 3)
				write(1, " ", 1);
			i++;
		}
		write(1, "\n", 1);
		j++;
	}
	return (0);
}

int	**free_board(int **board, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(board[j]);
		j++;
	}
	free(board);
	return (0);
}

int	**init_board(int size)
{
	int	**board;
	int	i;
	int	j;

	board = malloc(sizeof(int *) * size);
	if (!board)
		return (0);
	i = 0;
	while (i < size)
	{
		board[i] = malloc(sizeof(int) * size);
		if (!board[i])
			return (free_board(board, i));
		j = 0;
		while (j < size)
		{
			board[i][j] = 0;
			j++;
		}
		i++;
	}
	return (board);
}

int	main(int argc, char **argv)
{
	int	**board;
	int	board_size;
	int	ret;

	if (argc != 2)
	{
		write(1, "Error\n", 7);
		return (-1);
	}
	board_size = check_input(argv[1]);
	if (!board_size)
	{
		write(1, "Error\n", 7);
		return (-1);
	}
	board = init_board(board_size);
	if (!board)
		return (-1);
	ret = solve_board(board, board_size, argv[1]);
	if (ret)
		write(1, "Error\n", 7);
	return (ret);
}
