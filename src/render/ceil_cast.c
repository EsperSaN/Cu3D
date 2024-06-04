/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceil_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:44:37 by wave              #+#    #+#             */
/*   Updated: 2024/06/04 11:18:23 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	ceil_cast(mlx_image_t *img, int color)
{
	int			cur_x;
	t_int_point	start;
	t_int_point	end;

	cur_x = 1;
	end.y = (int)img->height / 2;
	start.y = 0;
	while (cur_x < (int)img->width)
	{
		start.x = cur_x;
		end.x = cur_x;
		draw_line(img, start, end, color);
		cur_x++;
	}
}
