/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:36:30 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 16:28:01 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	validate(const int fd)
{
	t_tetri	*tetris;
	char	buf[666];
	int		i;
	int		n;

	if ((i = read(fd, buf, 666)) == -1 || (i + 1) % 21 != 0)
		print_error();
	n = (i + 1) / 21;
	if (n > 26)
		print_error();
	if (val_string(buf, n, 0, 0) == -1)
		print_error();
	if (!(tetris = store_tetris(buf, n, 0, 0)))
		print_error();
	print_map(tetris, n, starting_size(n * 4));
}
