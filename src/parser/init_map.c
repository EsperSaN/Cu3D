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

	i = 0;
	(void)width;
	map = (char **)malloc(sizeof(char *) * (height + 1)); //recheck HHHH
	map[height] = NULL;
	while (i < height)
	{
		dprintf(2, "dup [%s] to -> ", smap[i + 6]); // fix this plz
		map[i] = ft_strdup(smap[i + 6]);
		*ft_strchr(map[i], '\n') = '\0';
		i++;
	}
	free2d(smap);
	return (map);
}
