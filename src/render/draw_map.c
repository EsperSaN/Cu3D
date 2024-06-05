/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 13:24:31 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/05 16:07:37 by pruenrua         ###   ########.fr       */
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

// void	draw_maps(t_data *d, mlx_image_t *image, t_maps_data *maps_data)
// {
// 	int			i;
// 	int			j;
// 	t_int_point	pos;
// 	int			scale;

// 	scale = get_maps_scale(maps_data, image);
// 	scale = 20;
// 	i = 0;
// 	pos.y = 0;
// 	while (maps_data->maps_array[i])
// 	{
// 		pos.x = 0;
// 		j = 0;
// 		while (maps_data->maps_array[i][j])
// 		{
// 			if (maps_data->maps_array[i][j] == WALL)
// 				draw_square(image, pos, scale - 1, get_rgba(255, 0, 0, 1000));
// 			else if (maps_data->maps_array[i][j] == FLOOR)
// 				draw_square(image, pos, scale - 1, get_rgba(0, 0, 0, 255));
// 			pos.x += scale;
// 			j++;
// 		}
// 		pos.y += scale;
// 		i++;
// 	}
// 	pos.x = (int)(d->player->pos.x * scale);
// 	pos.y = (int)(d->player->pos.y * scale);
// 	draw_square_center(image, pos, scale - 2, get_rgba(255, 255, 255, 255));
// }

void	draw_maps(t_data *d, t_raydata ray, mlx_image_t *image, t_maps_data *maps_data)
{
	t_int_point	pos;
	t_int_point cur_p;
	t_int_point draw;
	t_int_point dir;
	int			scale;
	
	cur_p.x = ray.ray_dir.x;
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
			if (pos.x >= 0 && \
				pos.y >= 0 && \
				pos.x < maps_data->maps_width && \
				pos.y < maps_data->maps_height && \
				maps_data->maps_array[pos.y][pos.x] && \
				maps_data->maps_array[pos.y][pos.x] == WALL)
				draw_square(image, draw, scale, get_rgba(255, 0, 0, 255));
			pos.x++;
			draw.x += scale;
			cur_p.x++;
		}
		draw.y += scale;
		pos.y++;
		cur_p.y++;
	}
	pos.x = image->width / 2;
	pos.y = image->height / 2;
	draw_square(image, pos, scale - 5, get_rgba(255, 255, 255, 255));
	dir.x = (pos.x + 15 * d->player->dir.x);
	dir.y = (pos.y + 15 * d->player->dir.y);
	draw_line(image, pos, dir, get_rgba(0, 255, 255, 255));

}
