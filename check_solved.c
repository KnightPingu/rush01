/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solved.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 20:01:50 by dopeyrat          #+#    #+#             */
/*   Updated: 2022/09/17 20:23:02 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_v_bis(int **board, int i, int value)
{
	int	j;
	int	count;
	int	old;

	count = 0;
	old = 0;
	j = 3;
	while (j >= 0)
	{
		if (board[i - 4][j] > old)
		{
			old = board[i - 4][j];
			count++;
		}
		j--;
	}
	if (count == value)
		return (1);
	return (0);
}

int	check_v(int **board, int i, int value)
{
	int	j;
	int	count;
	int	old;

	count = 0;
	old = 0;
	if (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (board[i][j] > old)
			{
				old = board[i][j];
				count++;
			}
			j++;
		}
	}
	else
		return (check_v_bis(board, i, value));
	if (count == value)
		return (1);
	return (0);
}

int	check_h_bis(int **board, int i, int value)
{
	int	j;
	int	count;
	int	old;

	count = 0;
	old = 0;
	j = 3;
	while (j >= 0)
	{
		if (board[j][i - 4] > old)
		{
			old = board[j][i - 4];
			count++;
		}
		j--;
	}
	if (count == value)
		return (1);
	return (0);
}

int	check_h(int **board, int i, int value)
{
	int	j;
	int	count;
	int	old;

	count = 0;
	old = 0;
	if (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (board[j][i] > old)
			{
				old = board[j][i];
				count++;
			}
			j++;
		}
	}
	else
		return (check_h_bis(board, i, value));
	if (count == value)
		return (1);
	return (0);
}

int	check_solved(int **board, char *str, int size)
{
	int	i;
	int	ret;

	i = 0;
	while (str[i])
	{
		if (i < size * 4)
			ret = check_v(board, i / 2, str[i] - 48);
		else
			ret = check_h(board, (i / 2) - (size * 2), str[i] - 48);
		if (!ret)
			return (0);
		i++;
		if (str[i] == 0)
			break ;
		i++;
	}
	return (1);
}
