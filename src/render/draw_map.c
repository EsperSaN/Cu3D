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

void draw_player(t_data *d, mlx_image_t *img, int scale)
{
	t_int_point p_pos;
	t_int_point p_dir;
	t_int_point p_fov;
	t_float_point p_dirr;

	p_pos.x = (int)(d->player->pos.x * scale);
	p_pos.y = (int)(d->player->pos.y * scale);
	p_dir.x = (int)(p_pos.x + (d->player->dir.x * scale));
	p_dir.y = (int)(p_pos.y + (d->player->dir.y * scale));
	draw_line(img, p_pos, p_dir, get_rgba(255,0,0,255));
	draw_square_center(img, p_pos, 5, get_rgba(255,255,255,255));
	draw_square_center(img, p_dir, 5, get_rgba(0,255,0,255));
	p_dirr = rotate_vector(d->player->dir, FIELD_OF_VIEW/2);
	p_fov.x = (int)(p_pos.x + (p_dirr.x * scale));
	p_fov.y = (int)(p_pos.y + (p_dirr.y * scale));
	draw_square_center(img, p_fov, 5, get_rgba(100,100,100,255));
	draw_line(img, p_pos, p_fov, get_rgba(255,0,0,255));
	p_dirr = rotate_vector(d->player->dir, (-(FIELD_OF_VIEW /2)));
	p_fov.x = (int)(p_pos.x + (p_dirr.x * scale));
	p_fov.y = (int)(p_pos.y + (p_dirr.y * scale));
	draw_square_center(img, p_fov, 5, get_rgba(100,100,100,255));
	draw_line(img, p_pos, p_fov, get_rgba(255,0,0,255));
}

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

void	draw_maps(t_data *d, mlx_image_t *image, t_maps_data *maps_data)
{
	int			i;
	int			j;
	t_int_point	pos;
	int			scale;

	scale = get_maps_scale(maps_data, image);
	i = 0;
	pos.x = 0;
	putreport("get scale done");
	dprintf(2, "img %d x %d\n", image->width, image->height);
	while (i < maps_data->maps_width)
	{
		pos.y = 0;
		j = 0;
		while (j < maps_data->maps_height)
		{
			dprintf(2, "try draw y [%d] x [%d] in [%d][%d] tile\n", pos.y, pos.x, j, i);
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
	draw_player(d, image, scale);
}
