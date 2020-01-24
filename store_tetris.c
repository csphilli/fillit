/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tetris.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 01:29:06 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 15:03:18 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetri	*store_tetris(char *buf, int n, int i, int j)
{
	t_tetri	*tetris;
	int		t_start;
	int		len;
	char	*str;

	if (!(tetris = (t_tetri*)malloc(sizeof(t_tetri) * n)))
		return (NULL);
	while (i < 21 * n - 1)
	{
		while (buf[i] != '#')
			i++;
		t_start = i;
		while (!(i % 21 == 20))
			i++;
		len = i - t_start;
		if (!(str = ft_strsub(buf, t_start, len)))
			print_error();
		tetris[j] = val_tetri(str, len, j, 0);
		free(str);
		i++;
		j++;
	}
	return (tetris);
}
