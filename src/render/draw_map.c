/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:31 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 23:58:44 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static	void	draw_player(mlx_image_t *image, t_int_point pos, int scale \
				, t_float_point pdir)
{
	t_int_point	dir;

	pos.x = image->width / 2;
	pos.y = image->height / 2;
	draw_square_center(image, pos, scale - 5, get_rgba(255, 255, 255, 255));
	dir.x = (pos.x + 15 * pdir.x);
	dir.y = (pos.y + 15 * pdir.y);
	draw_line(image, pos, dir, get_rgba(0, 255, 255, 255));
}

static void	put_maps(t_dm m, mlx_image_t *image, t_maps_data *maps_data)
{
	while (m.cur_p.x < 20 && m.pos.y >= 0)
	{
		if (m.pos.x >= 0 && m.pos.y >= 0 && m.pos.y < maps_data->maps_height && \
		m.pos.x < (int)(ft_strlen(maps_data->maps_array[m.pos.y])) && \
		maps_data->maps_array[m.pos.y][m.pos.x] == WALL)
			draw_square_center(image, m.draw, m.scale, \
										get_rgba(255, 0, 0, 255));
		m.pos.x++;
		m.draw.x += m.scale;
		m.cur_p.x++;
	}
}

void	draw_maps(t_data *d, mlx_image_t *image, t_maps_data *maps_data)
{
	t_dm	m;

	m.cur_p.y = 0;
	m.scale = image->width / 20;
	m.pos.y = (int)(d->player->pos.y) - 10;
	m.draw.y = 0;
	while (m.cur_p.y < 20)
	{
		m.cur_p.x = 0;
		m.pos.x = (int)(d->player->pos.x) - 10;
		m.draw.x = 0;
		put_maps(m, image, maps_data);
		m.draw.y += m.scale;
		m.pos.y++;
		m.cur_p.y++;
	}
	draw_player(image, m.pos, m.scale, d->player->dir);
	return ;
}
