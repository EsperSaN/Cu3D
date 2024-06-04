/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_squre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:43:35 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/04 11:12:16 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_square_center(mlx_image_t *image, t_int_point pos, \
											int size, int color)
{
	int	w;
	int	h;
	int	tmp;

	w = 0;
	h = 0;
	while (w < size)
	{
		tmp = pos.y - (size / 2);
		h = 0;
		while (h < size)
		{
			if ((tmp > 0 && pos.x > 0) && \
					(tmp <= (int)image->height && pos.x <= (int)image->width))
				mlx_put_pixel(image, pos.x - (size / 2), tmp, color);
			tmp++;
			h++;
		}
		pos.x++;
		w++;
	}
}

void	draw_square(mlx_image_t *image, t_int_point pos, int size, int color)
{
	int	w;
	int	h;
	int	tmp;

	w = 0;
	h = 0;
	while (w < size)
	{
		tmp = pos.y;
		h = 0;
		while (h < size)
		{
			if ((tmp > 0 && pos.x > 0) && \
					(tmp < (int)image->height && pos.x < (int)image->width))
				mlx_put_pixel(image, pos.x, tmp, color);
			tmp++;
			h++;
		}
		pos.x++;
		w++;
	}
}
