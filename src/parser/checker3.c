/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:41:03 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/07 21:14:21 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_map_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_map_element(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	count_value_line(char **data)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (data[i])
	{
		if (!is_map_line(data[i]))
		{
			dprintf(2, "in [%s] k++\n", data[i]);
			k++;
		}
		if (is_map_line(data[i]) && k != 6)
		{
			dprintf(2, "k != 6 case\n");
			return (-1);
		}
		i++;
	}
	if (k > 6)
		return (-1);
	return (k);
}

int	find_height(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i - 6);
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

int	get_ceil_floor(char *str, t_parser_data *res, char mode)
{
	int		i;
	int		color[3];
	int		rgb;
	char	**num;

	num = ft_split(str, ',');
	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			return (free2d(num), 0);
		i++;
	}
	if (i != 3)
		return (free2d(num), 0);
	i = -1;
	while (num[++i])
		color[i] = ft_atoi(num[i]);
	rgb = get_rgba(color[0], color[1], color[2], 255);
	if (mode == 'c' && res->ceil_color == 0)
		res->ceil_color = rgb;
	else if (mode == 'f' && res->floor_color == 0)
		res->floor_color = rgb;
	free2d(num);
	return (1);
}
