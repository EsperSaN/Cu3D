/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_texture_assets.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:32:26 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/13 00:04:01 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	try_get_texture(t_texture_assets *res)
{
	if (!res->east_texture || !res->west_texture \
		|| !res->north_texture || !res->south_texture)
	{
		puterror("bad png file");
		return (0);
	}
	return (1);
}

t_texture_assets	*set_texture_assets(t_data *data)
{
	t_texture_assets	*res;

	res = ft_calloc(sizeof(t_texture_assets), 1);
	if (res == NULL)
		return (NULL);
	res->ceil_color = data->parser_data->ceil_color;
	res->floor_color = data->parser_data->floor_color;
	res->east_texture = get_texture_png(data->parser_data->east_texture);
	res->west_texture = get_texture_png(data->parser_data->west_texture);
	res->north_texture = get_texture_png(data->parser_data->north_texture);
	res->south_texture = get_texture_png(data->parser_data->south_texture);
	if (!try_get_texture(res))
	{
		free_texture_assets(res);
		return (NULL);
	}
	return (res);
}
