/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:42:46 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/02 17:47:57 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	clear_image(mlx_image_t *frm, int color)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y < frm->width)
	{
		x = 0;
		while (x < frm->height)
		{
			mlx_put_pixel(frm, y, x, color);
			x++;
		}
		y++;
	}
}
