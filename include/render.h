/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:21:53 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 16:03:37 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
#define RENDER_H

#include "cube.h"

void	draw_square(mlx_image_t *image, t_int_pos pos, int size, int color);
void	clear_image(mlx_image_t *frm, int color);
void	draw_maps(mlx_image_t *image, t_maps_data *maps_data);
bool    prepare_render(t_data *data);
void    main_render(void *d);


#endif