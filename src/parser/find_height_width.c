/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_height_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:48 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 02:25:54 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_first_mapline(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (data[i] && is_map_line(data[i]) == -1)
			break ;
		i++;
	}
	return (i);
}

int	find_height(char **data)
{
	int	i;
	int	co;

	i = 0;
	co = 0;
	while (data[i] && -1 != is_map_line(data[i]))
		i++;
	while (data[i])
	{
		co++;
		i++;
	}
	return (co);
}

int	find_width(char **data)
{
	int	i;
	int	s;
	int	max;

	max = 0;
	i = find_first_mapline(data);
	s = 0;
	while (data[i])
	{
		s = ft_strlen(data[i]);
		if (s > max)
			max = s;
		i++;
	}
	return (max);
}
