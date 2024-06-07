/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:31 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/07 14:54:27 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static	void	draw_player(mlx_image_t *image, t_int_point pos, int scale \
				, t_float_point pdir)
{
	t_int_point	dir;

	pos.x = image->width / 2;
	pos.y = image->height / 2;
	draw_square(image, pos, scale - 5, get_rgba(255, 255, 255, 255));
	dir.x = (pos.x + 15 * pdir.x);
	dir.y = (pos.y + 15 * pdir.y);
	draw_line(image, pos, dir, get_rgba(0, 255, 255, 255));
}

void	draw_maps(t_data *d, mlx_image_t *image, t_maps_data *maps_data)
{
	t_int_point	pos;
	t_int_point	cur_p;
	t_int_point	draw;
	int			scale;

	cur_p.y = 0;
	scale = image->width / 20;
	pos.y = (int)(d->player->pos.y) - 10;
	draw.y = 0;
	while (cur_p.y < 20)
	{
		cur_p.x = 0;
		pos.x = (int)(d->player->pos.x) - 10;
		draw.x = 0;
		while (cur_p.x < 20 && pos.y >= 0)
		{
			if (pos.x >= 0 && pos.y >= 0 && \
			pos.x < maps_data->maps_width && pos.y < maps_data->maps_height && \
			maps_data->maps_array[pos.y][pos.x] && maps_data->maps_array[pos.y][pos.x] == WALL)
				draw_square(image, draw, scale, get_rgba(255, 0, 0, 255));
			pos.x++;
			draw.x += scale;
			cur_p.x++;
		}
		draw.y += scale;
		pos.y++;
		cur_p.y++;
	}
	draw_player(image, pos, scale, d->player->dir);
	return;
}
