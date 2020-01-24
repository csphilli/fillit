/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cphillip <cphillip@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 20:41:03 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/27 19:35:25 by cphillip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putstr_fd("usage: ./fillit <filename>\n", 2);
		exit(1);
	}
	validate(open(argv[1], O_RDONLY));
	return (0);
}
