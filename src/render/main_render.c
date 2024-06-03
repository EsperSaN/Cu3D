/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:18:34 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/03 19:26:16 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	main_render(void *d)
{
	t_data		*data;
	t_int_point	p_pos;

	data = (t_data *)d;
	p_pos.x = (int)data->player->pos.x;
	p_pos.y = (int)data->player->pos.y;

	clear_image(data->img_maps, get_rgba(0, 0, 0, 125));
	draw_maps(data, data->img_maps, data->maps);
	floor_cast(data->img_game, data->texture->floor_color);
	ceil_cast(data->img_game, data->texture->ceil_color);
	ray_casting(data->img_game, data);
}
