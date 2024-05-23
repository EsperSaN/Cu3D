/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_squre.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:43:35 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 15:48:26 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	draw_square(mlx_image_t *image, t_int_pos pos, int size, int color)
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
			mlx_put_pixel(image, pos.x, tmp, color);
			tmp++;
			h++;
		}
		pos.x++;
		w++;
	}
}
