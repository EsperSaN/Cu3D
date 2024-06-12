/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 16:42:01 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/13 00:01:25 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static char	**create_visitmap(int w, int h)
{
	int		i;
	int		j;
	char	**visited;

	i = 0;
	visited = (char **)malloc(sizeof(char *) * (h + 1));
	visited[h] = NULL;
	while (i < h)
	{
		visited[i] = (char *)malloc(sizeof(char) * (w + 1));
		j = 0;
		while (j < w)
		{
			visited[i][j] = '0';
			j++;
		}
		visited[i][w] = '0';
		i++;
	}
	return (visited);
}

static void	ft_floodfill_util(t_parser_data *data, char **visited, int x, int y)
{
	if (y > -1 && y < data->width && x > -1 && x < data->height \
		&& data->maps_data[x][y] && visited[x][y] == '0' \
		&& data->maps_data[x][y] != '1')
	{
		visited[x][y] = '3';
		ft_floodfill_util(data, visited, x + 1, y);
		ft_floodfill_util(data, visited, x - 1, y);
		ft_floodfill_util(data, visited, x, y + 1);
		ft_floodfill_util(data, visited, x, y - 1);
	}
}

static t_int_point	get_player_pos4(char **map)
{
	t_int_point	pos;
	int			i;
	int			j;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N' \
				|| map[i][j] == 'E' || map[i][j] == 'S')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

char	**ft_floodfill(t_parser_data *data)
{
	t_int_point	pos;
	char		**visited;
	int			h;
	int			w;

	pos = get_player_pos4(data->maps_data);
	h = data->height;
	w = data->width;
	visited = create_visitmap(w, h);
	ft_floodfill_util(data, visited, pos.y, pos.x);
	return (visited);
}
