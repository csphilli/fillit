/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 15:48:22 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 15:42:36 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	cool(int *theonewereset, int *theoneweincrease)
{
	*theonewereset = 0;
	*theoneweincrease = *theoneweincrease + 1;
}

static void	zero_array(int *array, int len)
{
	while (len-- > 0)
		array[len] = 0;
}

char		*solver(t_tetri *piece, int count, int size)
{
	char		*square;
	int			scount[count];
	int			i;
	int			old[count];

	square = create_square(size);
	zero_array(scount, count);
	i = 0;
	while (i < count)
	{
		if ((old[i] = check_piece(square, piece[i], size, scount[i])) == -2)
		{
			i--;
			if (i == -1)
				break ;
			undo(square, piece[i], size, old[i]);
			cool(&scount[i + 1], &scount[i]);
		}
		else
			i++;
	}
	if (i != -1)
		return (square);
	free(square);
	return (solver(piece, count, size + 1));
}
