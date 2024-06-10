/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:32 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 16:29:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**init_map(char **smap, int width, int height)
{
	char	**map;
	int		i;

	i = 0;
	(void)width;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	map[height] = NULL;
	while (i < height)
	{
		map[i] = ft_strdup(smap[i + 6]);
		i++;
	}
	free2d(smap);
	return (map);
}
