/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maps_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 20:53:49 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/25 18:50:44 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#define MAPS_CHARSET "10NSWE\n "
bool	is_only_char(char *str, char *to_have_str)
{
	int	i;
	int	j;
	int	count;
	int	to_have_len;

	count = 0;
	to_have_len = ft_strlen(to_have_str);
	i = 0;
	while (str[i])
	{
		j = 0;
		count = 0;
		while (to_have_str[j])
		{
			if (str[i] != to_have_str[j])
				count++;
			j++;
		}
		if (count == to_have_len)
			return (false);
		i++;
	}
	return (true);
}

char	**get_maps_array(char **maps)
{
	int		i;
	char	**ret;

	i = 0;
	while (maps[i])
	{
		if (is_only_char(maps[i], MAPS_CHARSET))
			break ;
		i++;
	}
	//dprintf(2, "maps[%d] -> %s\n", i, maps[i]);
	int count = 0;
	int tmpi = i;
	while (maps[i] && is_only_char(maps[i], MAPS_CHARSET))
	{
		i++;
		count++;
	}
	//dprintf(2, "count is %d out of count == [%s]\n", count,maps[i]);
	ret = ft_calloc(sizeof(char *), count + 1);
	i = 0;
	//dprintf(2, "here1");
	while (i < count)
	{
		ret[i] = ft_substr(maps[tmpi], 0, ft_strlen(maps[tmpi]));
		i++;
		tmpi++;
	}
	//dprintf(2, "%s\n", ret[0]);
	return (ret);
}
