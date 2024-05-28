/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:18:34 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 15:19:22 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	main_render(void *d)
{
	t_data *data;
    t_int_point p_pos;

    data = (t_data *)d;
    p_pos.x = (int)data->player->pos.x;
    p_pos.y = (int)data->player->pos.y;

    clear_image(data->img_maps, get_rgba(125,125,125,255));
    putreport("clear map done");
    draw_maps(data ,data->img_maps, data->maps);
    putreport("map done");
    floor_cast(data->img_game, data->texture->floor_color);
    putreport("floor done");
    ceil_cast(data->img_game, data->texture->ceil_color);
    putreport("ceil done");
    ray_casting(data->img_game, data);
    putreport("rc done\n");
    
}