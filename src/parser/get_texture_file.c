/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:40:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 20:30:27 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./parser.h"
// didnt get the out rager erg yet
char	*get_texture_file(char **map, char *indicater)
{
	int		i;
	char	**tmp;
	char	*ret;

	i = 0;
	while (map[i])
	{
		tmp = ft_split(map[i], ' ');
		dprintf(2, "[%s] -> %s -> %s\n", map[i], tmp[0], tmp[1]);
		dprintf(2, "here\n");
		if (tmp != NULL && is_same_str(tmp[0], indicater) && tmp[1] != NULL)
		{
			ret = ft_strdup(tmp[1]);
			free2d(tmp);
			return (ret);
		}
		dprintf(2, "here\n");
		free2d(tmp);
		tmp = NULL;
		i++;
	}
	return (NULL);
}