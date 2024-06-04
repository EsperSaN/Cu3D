/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:18:34 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/04 11:19:23 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	main_render(void *d)
{
	t_data		*data;

	data = (t_data *)d;
	clear_image(data->img_maps, get_rgba(0, 0, 0, 125));
	draw_maps(data, data->img_maps, data->maps);
	floor_cast(data->img_game, data->texture->floor_color);
	ceil_cast(data->img_game, data->texture->ceil_color);
	ray_casting(data->img_game, data);
}
