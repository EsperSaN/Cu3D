/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/11 00:42:38 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		get_element_check(char *type, char *text, t_parser_data *res)
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
	if (is_same_str(type, "C") && is_numline(text))
	{
		get_ceil_floor(text, res, 'c');
		return (1);
	}
	if (is_same_str(type, "F") && is_numline(text))
	{
		get_ceil_floor(text, res, 'f');
		return (1);
	}
	// need to improve in various case
}
