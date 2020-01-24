/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahakanen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 18:51:32 by ahakanen          #+#    #+#             */
/*   Updated: 2019/12/22 18:53:04 by ahakanen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	val_string(char *buf, int n, int i, int count)
{
	int	j;

	while (i < 21 * n - 1)
	{
		j = 0;
		while (j++ < 4)
		{
			if (buf[i] == '#' || buf[i] == '.')
			{
				if (buf[i] == '#')
					count++;
				i++;
			}
			else
				return (-1);
		}
		if (buf[i++] != '\n')
			return (-1);
		if (i % 21 == 20 && buf[i] == '\n' && count == 4)
		{
			count = 0;
			i++;
		}
	}
	return (count == 4 ? 1 : -1);
}
