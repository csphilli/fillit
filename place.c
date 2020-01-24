/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 19:35:17 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/17 19:35:49 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place(char *square, t_tetri piece, int size, int i)
{
	square[i] = piece.value;
	square[i + convert_piece(piece, 0, size)] = piece.value;
	square[i + convert_piece(piece, 1, size)] = piece.value;
	square[i + convert_piece(piece, 2, size)] = piece.value;
}
