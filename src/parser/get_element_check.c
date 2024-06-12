/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_element_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/13 00:21:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_tex(char *elm, char *tex)
{
	ft_putstr_fd(elm, 1);
	ft_putstr_fd(" : ", 1);
	ft_putstr_fd(tex, 1);
	ft_putchar_fd('\n', 1);
}

static int	ceil_floor_element(char *type, char *text, t_parser_data *res)
{
	char	*str;

	if (is_same_str(type, "C") && is_numline(text) && res->ceil_color == -1)
	{
		if (!get_ceil_floor(text, res, 'c'))
			return (0);
		str = ft_itoa(res->ceil_color);
		print_tex(type, str);
		free(str);
		return (1);
	}
	if (is_same_str(type, "F") && is_numline(text) && res->floor_color == -1)
	{
		if (!get_ceil_floor(text, res, 'f'))
			return (0);
		str = ft_itoa(res->floor_color);
		print_tex(type, str);
		free(str);
		return (1);
	}
	return (0);
}

static int	texture_element(char *type, char *text, t_parser_data *res)
{
	if (is_same_str(type, "NO") && !res->north_texture)
	{
		res->north_texture = ft_strdup(text);
		print_tex(type, text);
		return (1);
	}
	if (is_same_str(type, "SO") && !res->south_texture)
	{
		res->south_texture = ft_strdup(text);
		print_tex(type, text);
		return (1);
	}
	if (is_same_str(type, "EA") && !res->east_texture)
	{
		res->east_texture = ft_strdup(text);
		print_tex(type, text);
		return (1);
	}
	if (is_same_str(type, "WE") && !res->west_texture)
	{
		res->west_texture = ft_strdup(text);
		print_tex(type, text);
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
