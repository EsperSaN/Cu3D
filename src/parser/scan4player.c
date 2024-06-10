/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan4player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:13 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/11 00:58:37 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	scan4player(char **map)
{
	int	i;
	int	j;
	int	co;

	i = 0;
	co = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N' || \
					map[i][j] == 'E' || map[i][j] == 'S')
			{
				dprintf(2, "found!!! in %c [%d][%d]\n", map[i][j], i,j);
				co++;
			}
			j++;
		}
		i++;
	}
	if (co > 1 || co == 0)
		return (0);
	return (1);
}
