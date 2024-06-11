/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:32 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/11 14:41:13 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**init_map(char **smap, int width, int height)
{
	char	**map;
	int		i;
	int		f;

	i = 0;
	f = find_first_mapline(smap);
	(void)width;
	map = (char **)ft_calloc(sizeof(char *), (height + 1));
	map[height] = NULL;
	while (i < height)
	{
		map[i] = ft_strdup(smap[i + f]);
		if (ft_strchr(map[i], '\n') != 0)
			*ft_strchr(map[i], '\n') = '\0';
		i++;
	}
	free2d(smap);
	return (map);
}
