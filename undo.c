/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 19:55:00 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/12 19:55:19 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	undo(char *square, t_tetri piece, int size, int old)
{
	square[old] = '.';
	square[old + convert_piece(piece, 0, size)] = '.';
	square[old + convert_piece(piece, 1, size)] = '.';
	square[old + convert_piece(piece, 2, size)] = '.';
}
