/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 12:40:34 by dopeyrat          #+#    #+#             */
/*   Updated: 2022/09/17 20:07:45 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>

int	check_input(char *str);
int	solve_board(int **board, int size, char *str);
int	display_board(int **board, int size);
int	check_solved(int **board, char *str, int size);

#endif
