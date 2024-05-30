/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <tpoungla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-27 08:50:50 by tpoungla          #+#    #+#             */
/*   Updated: 2024-04-27 08:50:50 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int is_map_element(char c)
{
    if (c == 'S' || c == 'W' || c == 'E' \
        || c == 'N' || c == '0' || c == '1' || c == ' ')
        return (1);
    return (0);
}

int is_map_element_not_sp(char c)
{
    if (c == 'S' || c == 'W' || c == 'E' \
        || c == 'N' || c == '0' || c == '1')
        return (1);
    return (0);
}

int	ft_isspace(char c)
{
	if (c == '\r' || c == '\n' || c == '\f' )
		return (1);
	else if (c == '\v' || c == '\t' || c == ' ' )
		return (1);
	return (0);
}

int in_line(char *str, int start, int stop)
{
    int i;
    int f;

    f = 0;
    i = start;
    if (start == stop)
        return (0);
    while (i < stop)
    {
        if (!ft_isspace(str[i]))
            f++;
        i++;
    }
    if (f == 0)
        return (0);
    i = start;
    while (i < stop)
    {
        if (!is_map_element(str[i]))
            return (0);
        i++;
    }
    return (1);
}
int scanner(char *data)
{
    int i;
    int num[4];
    
    i = -1;
	while (i < 4)
		num[i++] = 0;
    i = 0;
    while (data[i])
    {
        if (data[i] == '\n')
        {
            num[1] += scanner_checker (num, 4, i, data);
            num[0] = in_line(data, i-num[2]+num[3], i);
            num[2] = 0;
            num[3] = 1;
        }
        num[2]++;
        i++;
    }
    num[1] += scanner_checker (num, 4, i, data);
    num[0] = in_line(data, i-num[2]+num[3], i);
    if ((num[0] + num[1]) > 1)
        return (0);
    return (1);
}

int is_map_line(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (!is_map_element(str[i]))
            return (0);
        i++;
    }
    return (1);
}
int count_value_line(char **data)
{
    int i;
    int k;
    
    i = 0;
    k = 0;
    while (data[i])
    {
        if (!is_map_line(data[i]))
            k++;
        if (is_map_line(data[i]) && k != 6)
            return (-1);
        i++;
    }
    if (k > 6)
        return (-1);
    return (k);
}

int    find_height(char **data)
{
    int     i;

    i = 0;
    while (data[i])
        i++;
    return (i-6);
}

int    find_width(char **data)
{
    int i;
    int s;
    int max;

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

int get_ceil_floor(char *str, t_parser_data *res, char mode)
{
	int		i;
    int     color[3];
    int     rgb;
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

int check_resource(char **map, t_parser_data *res)
{
    int i = 0;
    int j;
    char **element;

    while (i < 6)
    {
        element = ft_split(map[i], ' ');
        j = 0;
        while (element[j])
            j++;
        if (j != 2)
        {
            free2d(element);
            return(0);   
        }
        i++;
        get_texture_check(element[0], element[1], res);
        if (is_same_str(element[0], "C"))
            get_ceil_floor(element[1], res, 'c');
        if (is_same_str(element[0], "F"))
            get_ceil_floor(element[1], res, 'f');
        free2d(element);
    }
    return (1);
}

int src_checker(t_parser_data *res)
{
    if (!res->north_texture || !res->south_texture \
    || !res->west_texture || !res->east_texture \
    || !res->ceil_color || !res->floor_color)
        return (0);
    if (!is_file_readable(res->north_texture) || !is_right_extension(res->north_texture, ".png"))
        return (0);
    if (!is_file_readable(res->south_texture) || !is_right_extension(res->south_texture, ".png"))
        return (0);
    if (!is_file_readable(res->west_texture) || !is_right_extension(res->west_texture, ".png"))
        return (0);
    if (!is_file_readable(res->east_texture) || !is_right_extension(res->east_texture, ".png"))
        return (0);
    return (1);
}

int scan4player (char **map)
{
    int	i;
	int j;
	int co;

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

int border_checker(char **map)
{
    int	i;
	int j;
    int h;

	i = -1;
    h = find_height(map) + 5;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
            if (map[i][j] != '1' && is_map_element_not_sp(map[i][j]))
            {
                if (i == 0 || i == h)
                    return (0);
                if (!is_map_element_not_sp(map[i][j-1]) \
                    || !is_map_element_not_sp(map[i+1][j]) \
                    || !is_map_element_not_sp(map[i-1][j]) \
                    || !is_map_element_not_sp(map[i][j+1]))
                    return (0);
            }
			j++;
		}
	}
    return (1);
}

int scanner_checker (int num[], int n, int i, char *data)
{
    if (num[0] && !in_line(data, i-num[2]+num[3], i))
        return (1);
    return (0);
}
