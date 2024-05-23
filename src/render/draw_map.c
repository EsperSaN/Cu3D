/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:50:07 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/28 00:44:09 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static int	get_maps_scale(t_maps_data *maps_data, mlx_image_t *img)
{
	int	scale_x;
	int	scale_y;
	int	scale;

	scale_x = img->width / maps_data->maps_width;
	scale_y = img->height / maps_data->maps_height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale);
}

void	draw_maps(mlx_image_t *image, t_maps_data *maps_data)
{
	int			i;
	int			j;
	t_int_pos	pos;
	int			scale;

	scale = get_maps_scale(maps_data, image);
	i = 0;
	pos.x = 0;
	while (i < maps_data->maps_width)
	{
		pos.y = 0;
		j = 0;
		while (j < maps_data->maps_width)
		{
			if (maps_data->maps_array[j][i] != FLOOR)
				draw_square(image, pos, scale - 1, get_rgba(255, 0, 0, 1000));
			else
				draw_square(image, pos, scale - 1, get_rgba(0, 0, 0, 255));
			pos.y += scale;
			j++;
		}
		pos.x += scale;
		i++;
	}
}
