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

    //clear_image(data->img_game, get_rgba(255, 0, 0, 255));
    clear_image(data->img_maps, get_rgba(255,255,255,255));
    draw_maps(data ,data->img_maps, data->maps);
    
    
    // mlx_delete_image(data->mlx, data->img_game);
    // mlx_delete_image(data->mlx, data->img_maps);
    // mlx_terminate(data->mlx);

}