/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_height_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:48 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 16:28:49 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_first_mapline(char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (is_map_line(data[i]) == -1)
			break;
		i++;
	}
	return (i);
}

int	find_height(char **data)
{
	int	i;
	int f;
	int co;

	i = 0;
	co = 0;
	f = 0;
	while (data[i])
	{
		// printf("line is <%s>", data[i]);
		if (is_map_line(data[i]) == -1)
		{
			co++;
			f = 1;
		}
		if (f && is_map_line(data[i]) != -1)
			break ;
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
	i = 6;
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
