/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_render.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:55:02 by wave              #+#    #+#             */
/*   Updated: 2024/06/03 19:23:26 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

bool	init_window(t_data *data)
{
	data->mlx = mlx_init(WIN_WIDTH, WIN_HIGHT, WIN_TITLE, WIN_RESIZE);
	if (data->mlx == NULL)
		return (puterror(MLX_INIT_FAIL), false);
	data->img_game = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HIGHT);
	if (data->img_game == NULL || \
		mlx_image_to_window(data->mlx, data->img_game, 0, 0) == -1)
		return (puterror(MLX_IMG_FAIL), false);
	data->img_maps = mlx_new_image(data->mlx, MINI_MAPS_SIZE, MINI_MAPS_SIZE);
	if (data->img_maps == NULL || \
		mlx_image_to_window(\
		data->mlx, data->img_maps, MINI_MAPS_OFFSET, MINI_MAPS_OFFSET) == -1)
		return (puterror(MLX_IMG_FAIL), false);
	return (true);
}

bool	init_event_hook(t_data *data)
{
	return (true);
}

bool	init_first_frame(t_data *data)
{
	return (true);
}

bool	prepare_render(t_data *data)
{
	if (init_window(data) == false || \
			init_event_hook(data) == false || \
				init_first_frame(data) == false)
		return (false);
	return (true);
}
