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
# define RENDER_H

# include "cube.h"

void				key_hook(void *data);
void				draw_square(mlx_image_t *image, \
						t_int_point pos, int size, int color);
void				draw_square_center(mlx_image_t *image, \
						t_int_point pos, int size, int color);
void				clear_image(mlx_image_t *frm, int color);
void				draw_maps(t_data *d, mlx_image_t *image, \
						t_maps_data *maps_data);
bool				prepare_render(t_data *data);
void				main_render(void *d);
int					draw_line(mlx_image_t *img, t_int_point head, \
						t_int_point tail, int color);
void				floor_cast(mlx_image_t *img, int color);
void				ceil_cast(mlx_image_t *img, int color);
int					ray_casting(mlx_image_t *img, t_data *d);
int					draw_verline(mlx_image_t *frame, int x, int y, int to_y, int color);

#endif