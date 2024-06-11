/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/12 02:38:12 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	ceil_floor_element(char *type, char *text, t_parser_data *res)
{
	if (is_same_str(type, "C") && is_numline(text) && res->ceil_color == -1)
	{
		get_ceil_floor(text, res, 'c');
		return (1);
	}
	if (is_same_str(type, "F") && is_numline(text) && res->floor_color == -1)
	{
		get_ceil_floor(text, res, 'f');
		return (1);
	}
	return (0);
}

int	texture_element(char *type, char *text, t_parser_data *res)
{
	if (is_same_str(type, "NO") && !res->north_texture)
	{
		res->north_texture = ft_strdup(text);
		return (1);
	}
	if (is_same_str(type, "SO") && !res->south_texture)
	{
		res->south_texture = ft_strdup(text);
		return (1);
	}
	if (is_same_str(type, "EA") && !res->east_texture)
	{
		res->east_texture = ft_strdup(text);
		return (1);
	}
	if (is_same_str(type, "WE") && !res->west_texture)
	{
		res->west_texture = ft_strdup(text);
		return (1);
	}
	return (0);
}

int	get_element_check(char *type, char *text, t_parser_data *res)
{
	if (texture_element(type, text, res) == 1 || \
		ceil_floor_element(type, text, res) == 1)
		return (1);
	return (0);
}
