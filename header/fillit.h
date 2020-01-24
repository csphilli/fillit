/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:52:52 by cphillip          #+#    #+#             */
/*   Updated: 2019/12/27 16:04:12 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct	s_tetri
{
	char	value;
	int		x[3];
	int		y[3];
}				t_tetri;

int				print_error();
void			validate(const int fd);
int				val_string(char *buf, int n, int i, int count);
t_tetri			*store_tetris(char *buf, int n, int i, int j);
t_tetri			val_tetri(char *buf, int slen, int j, int i);
int				check_piece(char *square, t_tetri piece, int size, int count);
int				convert_piece(t_tetri piece, int i, int size);
char			*create_square(int size);
void			place(char *square, t_tetri piece, int size, int i);
char			*solver(t_tetri *piece, int count, int size);
void			undo(char *square, t_tetri piece, int size, int old);
int				starting_size(int n);
void			print_map(t_tetri *piece, int count, int size);

#endif
