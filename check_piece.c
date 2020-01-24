/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 16:34:57 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 14:55:44 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_piece(char *square, t_tetri piece, int size, int count)
{
	int			old;
	int			i;
	int			j;

	i = 0;
	j = 0;
	old = -2;
	while ((i + convert_piece(piece, 2, size)) < (size * size + size))
	{
		if (square[i] == '.')
			if (square[i + convert_piece(piece, 0, size)] == '.')
				if (square[i + convert_piece(piece, 1, size)] == '.')
					if (square[i + convert_piece(piece, 2, size)] == '.')
						j++;
		if (j > count)
		{
			place(square, piece, size, i);
			old = i;
			break ;
		}
		i++;
	}
	return (old);
}
