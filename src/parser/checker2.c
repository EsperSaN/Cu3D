/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:40:26 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/05 14:38:22 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	check_resource(char **map, t_parser_data *res)
{
	int		i;
	int		j;
	char	**element;

	i = 0;
	while (i < 6)
	{
		element = ft_split(map[i], ' ');
		j = 0;
		while (element[j])
			j++;
		if (j != 2)
		{
			free2d(element);
			return (0);
		}
		i++;
		get_texture_check(element[0], element[1], res);
		if (is_same_str(element[0], "C") && is_numline(element[1]))
			get_ceil_floor(element[1], res, 'c');
		if (is_same_str(element[0], "F") && is_numline(element[1]))
			get_ceil_floor(element[1], res, 'f');
		free2d(element);
	}
	return (1);
}

int	src_checker(t_parser_data *res)
{
	if (!res->north_texture || !res->south_texture \
	|| !res->west_texture || !res->east_texture \
	|| !res->ceil_color || !res->floor_color)
		return (0);
	if (!is_file_readable(res->north_texture) \
		|| !is_right_extension(res->north_texture, ".png"))
		return (0);
	if (!is_file_readable(res->south_texture) \
		|| !is_right_extension(res->south_texture, ".png"))
		return (0);
	if (!is_file_readable(res->west_texture) \
		|| !is_right_extension(res->west_texture, ".png"))
		return (0);
	if (!is_file_readable(res->east_texture) \
		|| !is_right_extension(res->east_texture, ".png"))
		return (0);
	return (1);
}

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
			if (map[i][j] == 'W' || map[i][j] == 'N')
				co++;
			if (map[i][j] == 'E' || map[i][j] == 'S')
				co++;
			j++;
		}
		i++;
	}
	if (co > 1 || co == 0)
		return (0);
	return (1);
}

int	border_checker(t_parser_data *data, char **map)
{
	int		i;
	int		j;
	char	**visited;

	visited = ft_floodfill(data);
	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '1' && is_map_not_sp(map[i][j]) \
				&& visited[i][j] == '3')
			{
				if (i == 0 || i == find_height(map) + 5 \
					|| !is_map_not_sp(map[i][j - 1]) \
					|| !is_map_not_sp(map[i + 1][j]) \
					|| !is_map_not_sp(map[i - 1][j]) \
					|| !is_map_not_sp(map[i][j + 1]))
					return (free2d(visited), 0);
			}
			j++;
		}
	}
	return (free2d(visited), 1);
}

int	scanner_checker(int num[], int i, char *data)
{
	if (num[0] && !in_line(data, i - num[2] + num[3], i))
		return (1);
	return (0);
}
