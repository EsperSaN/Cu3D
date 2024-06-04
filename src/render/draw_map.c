/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:50:07 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/04 18:38:58 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

/*void draw_player(t_data *d, mlx_image_t *img, int scale)
{

	t_int_point p_dir;
	t_int_point p_fov;
	t_int_point p_pane;
	t_float_point p_dirr;
	t_int_point p_pos;
	p_pos.x = (int)(d->player->pos.x * scale);
	p_pos.y = (int)(d->player->pos.y * scale);
	p_dir.x = (int)(p_pos.x + (d->player->dir.x * scale));
	p_dir.y = (int)(p_pos.y + (d->player->dir.y * scale));
	draw_line(img, p_pos, p_dir, get_rgba(255,0,0,255));
	draw_square_center(img, p_pos, 5, get_rgba(255,255,255,255));
	draw_square_center(img, p_dir, 5, get_rgba(0,255,0,255));
	p_pane = p_dir;
	p_pane.x += d->player->pane.x * scale;
	p_pane.y += d->player->pane.y * scale;
	draw_line(img, p_dir, p_pane, get_rgba(255,0,0,255));
	p_pane = p_dir;
	p_pane.x -= d->player->pane.x * scale;
	p_pane.y -= d->player->pane.y * scale;
	draw_line(img, p_dir, p_pane, get_rgba(255,0,0,255));
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
} */

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

	(void)d;
	scale = get_maps_scale(maps_data, image);
	i = 0;
	pos.y = 0;
	while (maps_data->maps_array[i])
	{
		pos.x = 0;
		j = 0;
		while (maps_data->maps_array[i][j])
		{
			if (maps_data->maps_array[i][j] != FLOOR)
				draw_square(image, pos, scale - 1, get_rgba(255, 0, 0, 1000));
			else
				draw_square(image, pos, scale - 1, get_rgba(0, 0, 0, 255));
			pos.x += scale;
			j++;
		}
		pos.y += scale;
		i++;
	}
	pos.x = (int)(d->player->pos.x * scale);
	pos.y = (int)(d->player->pos.y * scale);
	draw_square_center(image, pos, scale - 2, get_rgba(255, 255, 255, 255));
}
