/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 18:41:08 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/13 18:42:39 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*create_square(int size)
{
	char	*square;
	int		i;

	if (!(square = ft_strnew(size * size + size)))
		print_error();
	i = 0;
	while (i < size * size + size)
	{
		if ((i + 1) % (size + 1) == 0)
			square[i] = '\n';
		else
			square[i] = '.';
		i++;
	}
	return (square);
}
