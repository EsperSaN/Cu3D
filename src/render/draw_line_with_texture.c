/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_with_texture.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:39:22 by wave              #+#    #+#             */
/*   Updated: 2024/06/03 15:41:27 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static t_texture	*find_tex_to_draw(t_data *d, t_raydata *ray)
{
	if (ray->ray_dir.x < 0 && ray->ray_dir.y < 0)
	{
		if (ray->hit_side == Y_LINE)
			return (d->texture->north_texture);
		else
			return (d->texture->west_texture);
	}
	if (ray->ray_dir.x == 0 && ray->ray_dir.y < 0)
		return (d->texture->north_texture);
	if (ray->ray_dir.x > 0 && ray->ray_dir.y < 0)
	{
		if (ray->hit_side == Y_LINE)
			return (d->texture->north_texture);
		else
			return (d->texture->east_texture);
	}
	if (ray->ray_dir.x > 0 && ray->ray_dir.y == 0)
		return (d->texture->east_texture);
	if (ray->ray_dir.x > 0 && ray->ray_dir.y > 0)
	{
		if (ray->hit_side == Y_LINE)
			return (d->texture->south_texture);
		else
			return (d->texture->east_texture);
	}
	if (ray->ray_dir.x == 0 && ray->ray_dir.y > 0)
		return (d->texture->south_texture);
	if (ray->ray_dir.x < 0 && ray->ray_dir.y > 0)
	{
		if (ray->hit_side == Y_LINE)
			return (d->texture->south_texture);
		else
			return (d->texture->west_texture);
	}
	if (ray->ray_dir.x < 0 && ray->ray_dir.y == 0)
		return (d->texture->west_texture);
}

static void	put_texture(t_raydata *ray, t_dtex t, \
							mlx_image_t *img, int x_to_draw)
{
	float	tex_pos;
	int		cur_y;
	int		tex_cor_y;

	tex_pos = \
		(ray->line_s - img->height / 2 + ray->line_hight / 2) * t.step_tex;
	cur_y = ray->line_s;
	while (cur_y < ray->line_e)
	{
		tex_cor_y = (int)tex_pos & (t.texture->height - 1);
		tex_pos += t.step_tex;
		t.color = t.texture->pixel_array[tex_cor_y][t.tex_cor_x];
		mlx_put_pixel(img, x_to_draw, cur_y, t.color);
		cur_y++;
	}
}

void	draw_line_with_texture(t_raydata *ray, t_data *data, \
								mlx_image_t *img, int x_to_draw)
{
	t_dtex	t;

	if (ray->hit_side == X_LINE)
		t.wall_cor_x = \
			data->player->pos.y + ray->perp_wall_distant * ray->ray_dir.y;
	else if (ray->hit_side == Y_LINE)
		t.wall_cor_x = \
			data->player->pos.x + ray->perp_wall_distant * ray->ray_dir.x;
	t.wall_cor_x -= floor(t.wall_cor_x);
	t.texture = find_tex_to_draw(data, ray);
	t.tex_cor_x = (int)(t.wall_cor_x * (float)t.texture->width);
	if (ray->hit_side == 0 && ray->ray_dir.x > 0)
		t.tex_cor_x = t.texture->width - t.tex_cor_x - 1;
	if (ray->hit_side == 1 && ray->ray_dir.y < 0)
		t.tex_cor_x = t.texture->width - t.tex_cor_x - 1;
	t.step_tex = (t.texture->height * 1.0 / ray->line_hight * 1.0);
	put_texture(ray, t, img, x_to_draw);
}
