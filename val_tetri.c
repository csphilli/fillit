/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_tetri.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 03:00:10 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 19:24:15 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		find_tetri3(char *buf, int len)
{
	if (len > 7 && buf[1] == '#' && buf[2] == '#' && buf[2 + 5] == '#')
		return (17);
	if (len > 10 && buf[1] == '#' && buf[0 + 5] == '#' && buf[0 + 10] == '#')
		return (18);
	if (len > 7 && buf[0 + 5] == '#' && buf[1 + 5] == '#' && \
		buf[2 + 5] == '#')
		return (19);
	print_error();
	return (-1);
}

static int		find_tetri2(char *buf, int len)
{
	if (len > 5 && buf[1] == '#' && buf[2] == '#' && buf[0 + 5] == '#')
		return (9);
	if (len > 11 && buf[1] == '#' && buf[1 + 5] == '#' && buf[1 + 10] == '#')
		return (10);
	if (len > 5 && buf[0 + 5] == '#' && buf[-1 + 5] == '#' && \
		buf[-2 + 5] == '#')
		return (11);
	if (len > 11 && buf[0 + 5] == '#' && buf[1 + 5] == '#' && \
		buf[1 + 10] == '#')
		return (12);
	if (len > 5 && buf[1] == '#' && buf[-1 + 5] == '#' && buf[0 + 5] == '#')
		return (13);
	if (len > 9 && buf[-1 + 5] == '#' && buf[0 + 5] == '#' && \
		buf[-1 + 10] == '#')
		return (14);
	if (len > 7 && buf[1] == '#' && buf[1 + 5] == '#' && buf[2 + 5] == '#')
		return (15);
	if (len > 10 && buf[0 + 5] == '#' && buf[-1 + 10] == '#' && \
		buf[0 + 10] == '#')
		return (16);
	return (find_tetri3(buf, len));
}

static int		find_tetri(char *buf, int len)
{
	if (len > 3 && buf[1] == '#' && buf[2] == '#' && buf[3] == '#')
		return (1);
	if (len > 15 && buf[0 + 5] == '#' && buf[0 + 10] == '#' && \
		buf[0 + 15] == '#')
		return (2);
	if (len > 6 && buf[1] == '#' && buf[0 + 5] == '#' && buf[1 + 5] == '#')
		return (3);
	if (len > 10 && buf[0 + 5] == '#' && buf[1 + 5] == '#' && \
		buf[0 + 10] == '#')
		return (4);
	if (len > 6 && buf[0 + 5] == '#' && buf[-1 + 5] == '#' && \
		buf[1 + 5] == '#')
		return (5);
	if (len > 10 && buf[0 + 5] == '#' && buf[-1 + 5] == '#' && \
		buf[0 + 10] == '#')
		return (6);
	if (len > 6 && buf[1] == '#' && buf[2] == '#' && buf[1 + 5] == '#')
		return (7);
	if (len > 11 && buf[0 + 5] == '#' && buf[0 + 10] == '#' && \
		buf[1 + 10] == '#')
		return (8);
	return (find_tetri2(buf, len));
}

static t_tetri	val_tetri2(int j, int i)
{
	t_tetri tetri;

	if (i == 10)
		tetri = (t_tetri) { ('A' + j), {1, 1, 1}, {0, 1, 2}};
	if (i == 11)
		tetri = (t_tetri) { ('A' + j), {-2, -1, 0}, {1, 1, 1}};
	if (i == 12)
		tetri = (t_tetri) { ('A' + j), {0, 1, 1}, {1, 1, 2}};
	if (i == 13)
		tetri = (t_tetri) { ('A' + j), {1, -1, 0}, {0, 1, 1}};
	if (i == 14)
		tetri = (t_tetri) { ('A' + j), {-1, 0, -1}, {1, 1, 2}};
	if (i == 15)
		tetri = (t_tetri) { ('A' + j), {1, 1, 2}, {0, 1, 1}};
	if (i == 16)
		tetri = (t_tetri) { ('A' + j), {0, -1, 0}, {1, 2, 2}};
	if (i == 17)
		tetri = (t_tetri) { ('A' + j), {1, 2, 2}, {0, 0, 1}};
	if (i == 18)
		tetri = (t_tetri) { ('A' + j), {1, 0, 0}, {0, 1, 2}};
	if (i == 19)
		tetri = (t_tetri) { ('A' + j), {0, 1, 2}, {1, 1, 1}};
	return (tetri);
}

t_tetri			val_tetri(char *buf, int slen, int j, int i)
{
	t_tetri	tetri;

	i = find_tetri(buf, slen);
	if (i == 1)
		tetri = (t_tetri) { ('A' + j), {1, 2, 3}, {0, 0, 0}};
	else if (i == 2)
		tetri = (t_tetri) { ('A' + j), {0, 0, 0}, {1, 2, 3}};
	else if (i == 3)
		tetri = (t_tetri) { ('A' + j), {1, 0, 1}, {0, 1, 1}};
	else if (i == 4)
		tetri = (t_tetri) { ('A' + j), {0, 1, 0}, {1, 1, 2}};
	else if (i == 5)
		tetri = (t_tetri) { ('A' + j), {-1, 0, 1}, {1, 1, 1}};
	else if (i == 6)
		tetri = (t_tetri) { ('A' + j), {-1, 0, 0}, {1, 1, 2}};
	else if (i == 7)
		tetri = (t_tetri) { ('A' + j), {1, 2, 1}, {0, 0, 1}};
	else if (i == 8)
		tetri = (t_tetri) { ('A' + j), {0, 0, 1}, {1, 2, 2}};
	else if (i == 9)
		tetri = (t_tetri) { ('A' + j), {1, 2, 0}, {0, 0, 1}};
	else
		return (val_tetri2(j, i));
	return (tetri);
}
