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

<<<<<<< HEAD
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
    int k;
    int f;
    int num[2];
    
    f = 0;
    i = 0;
    k = 0;
    num[0] = 0;
    num[1] = 0;
    while (data[i])
    {
        if (data[i] == '\n')
        {
            if (num[0] && !in_line(data, i-k+f, i))
                num[1]++;
            num[0] = in_line(data, i-k+f, i);
            k = 0;
            f = 1;
        }
        k++;
        i++;
    }
    if (num[0] && !in_line(data, i-k+f, i))
        num[1]++;
    num[0] = in_line(data, i-k+f, i);
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
        {
            free2d(num);
			return (0);//error not 0-255
        }
		i++;
	}
	if (i != 3)
    {
        free2d(num);
		return (0);
    }
	i = 0;
	while (num[i])
	{
		color[i] = ft_atoi(num[i]);
		i++;
	}
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
        if (is_same_str(element[0], "NO") && !res->north_texture)
            res->north_texture = ft_strdup(element[1]);
        if (is_same_str(element[0], "SO") && !res->south_texture)
            res->south_texture = ft_strdup(element[1]);
        if (is_same_str(element[0], "EA") && !res->east_texture)
            res->east_texture = ft_strdup(element[1]);
        if (is_same_str(element[0], "WE") && !res->west_texture)
            res->west_texture = ft_strdup(element[1]);
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
    if (!is_file_readable(res->north_texture))
        return (0);
    if (!is_file_readable(res->south_texture))
        return (0);
    if (!is_file_readable(res->west_texture))
        return (0);
    if (!is_file_readable(res->east_texture))
        return (0);
    return (1);
}

void free_texture(t_parser_data *res)
{
    if (res->east_texture)
		free(res->east_texture);
	if (res->north_texture)
		free(res->north_texture);
	if (res->west_texture)
		free(res->west_texture);
	if (res->south_texture)
		free(res->south_texture);
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
            if (map[i][j] == 'W')
                co++;
            if (map[i][j] == 'N')
                co++;
            if (map[i][j] == 'E')
                co++;
            if (map[i][j] == 'S')
                co++;
			j++;
		}
		i++;
	}
    if (co > 1)
        return (0);
    return (1);
}

int border_checker(char **map)
{
    int	i;
	int j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
            if (map[i][j] != '1' && is_map_element_not_sp(map[i][j]))
            {
                if (!is_map_element_not_sp(map[i][j-1]))
                    return (0);
                if (!is_map_element_not_sp(map[i-1][j]))
                    return (0);
                if (!is_map_element_not_sp(map[i][j+1]))
                    return (0);
                if (!is_map_element_not_sp(map[i+1][j]))
                    return (0);
            }
			j++;
		}
		i++;
	}
    return (1);
}
