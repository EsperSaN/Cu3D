/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:21:53 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/07 15:49:31 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "cube.h"

bool				set_from_parser_data(t_data *data);

t_maps_data			*set_maps_data(t_data *data);

t_texture_assets	*set_texture_assets(t_data *data);

void				key_hook(void *data);

void				draw_square(mlx_image_t *image, t_int_point pos, \
										int size, int color);

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

void				do_dda(t_raydata *ray, char **maps);

void				find_range_to_draw(t_raydata *ray, int img_height);

void				draw_line_with_texture(t_raydata *ray, t_data *data, \
										mlx_image_t *img, int x_to_draw);

int					ray_casting(mlx_image_t *img, t_data *d);

void				init_ray(t_raydata *ray, t_player_data *play_data);

#endif