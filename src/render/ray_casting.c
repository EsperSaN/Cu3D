/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:57:08 by wave              #+#    #+#             */
/*   Updated: 2024/06/07 14:15:10 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	ray_casting(mlx_image_t *img, t_data *d)
{
	int				cur_w;
	t_raydata		ray;
	t_player_data	p;

	cur_w = 0;
	p = *(d->player);
	while (cur_w < (int)img->width)
	{
		ray.camera.x = 2 * (cur_w / (float)img->width) - 1.0f;
		init_ray(&ray, &p);
		do_dda(&ray, d->maps->maps_array);
		find_range_to_draw(&ray, img->height);
		draw_line_with_texture(&ray, d, img, cur_w);
		cur_w++;
	}
	draw_maps(d, d->img_maps, d->maps);
	return (1);
}
