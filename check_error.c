/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dopeyrat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:22:08 by dopeyrat          #+#    #+#             */
/*   Updated: 2022/09/17 18:19:11 by dopeyrat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	check_input(char *str)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (str[i])
	{
		if (!(str[i] >= '1' && str[i] <= '4'))
			err = 1;
		i++;
		if (!str[i])
			break ;
		if (str[i] != ' ')
			err = 1;
		i++;
	}
	i++;
	i = i / 2;
	if (err || i % 4 || i % 4 > 9)
		return (0);
	return (i / 4);
}
