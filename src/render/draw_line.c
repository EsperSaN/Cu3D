/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:48:04 by wave              #+#    #+#             */
/*   Updated: 2024/06/02 17:49:16 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

int	draw_verline(mlx_image_t *frame, int x, int y, int to_y, int color)
{
	int	tmp;

	if (x >= frame->width)
		x = frame->width - 1;
	if (y == 0)
		y = 1;
	if (to_y >= frame->height)
		y = frame->height - 1;
	while (y++ < to_y)
		mlx_put_pixel(frame, x, y, color);
}

int	draw_line(mlx_image_t *img, t_int_point head, t_int_point tail, int color)
{
	t_int_point		delta;
	t_float_point	inc;
	t_float_point	cur;
	int				step;

	delta.x = tail.x - head.x;
	delta.y = tail.y - head.y;
	step = abs(delta.x);
	if (step < abs(delta.y))
		step = abs(delta.y);
	inc.x = (float)delta.x / (float)step;
	inc.y = (float)delta.y / (float)step;
	cur.x = head.x;
	cur.y = head.y;
	while (step >= 0)
	{
		if (cur.x > 0 && cur.x < img->height && \
					cur.y > 0 && cur.y < img->height)
			mlx_put_pixel(img, (int)cur.x, (int)cur.y, color);
		cur.x += inc.x;
		cur.y += inc.y;
		step--;
	}
}
