/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 00:25:25 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 19:14:35 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	print_map(t_tetri *piece, int count, int size)
{
	char	*map;

	if (!(map = solver(piece, count, size)))
		print_error();
	ft_putstr(map);
	exit(0);
}
