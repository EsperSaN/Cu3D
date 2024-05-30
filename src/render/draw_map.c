/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 15:50:07 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/28 00:44:09 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void draw_player(t_data *d, mlx_image_t *img, int scale)
{
	t_int_point p_pos;
	t_int_point p_dir;
	t_int_point p_fov;
	t_int_point p_pane;
	t_float_point p_dirr;

	p_pos.x = (int)(d->player->pos.x * scale);
	p_pos.y = (int)(d->player->pos.y * scale);
	p_dir.x = (int)(p_pos.x + (d->player->dir.x * scale));
	p_dir.y = (int)(p_pos.y + (d->player->dir.y * scale));
	draw_line(img, p_pos, p_dir, get_rgba(255,0,0,255));
	draw_square_center(img, p_pos, 5, get_rgba(255,255,255,255));
	draw_square_center(img, p_dir, 5, get_rgba(0,255,0,255));
	p_pane = p_dir;
	p_pane.x += d->player->pane.x * scale;
	p_pane.y += d->player->pane.y * scale;
	draw_line(img, p_dir, p_pane, get_rgba(255,0,0,255));
	p_pane = p_dir;
	p_pane.x -= d->player->pane.x * scale;
	p_pane.y -= d->player->pane.y * scale;
	draw_line(img, p_dir, p_pane, get_rgba(255,0,0,255));
	p_dirr = rotate_vector(d->player->dir, FIELD_OF_VIEW/2);
	p_fov.x = (int)(p_pos.x + (p_dirr.x * scale));
	p_fov.y = (int)(p_pos.y + (p_dirr.y * scale));
	draw_square_center(img, p_fov, 5, get_rgba(100,100,100,255));
	draw_line(img, p_pos, p_fov, get_rgba(255,0,0,255));
	p_dirr = rotate_vector(d->player->dir, (-(FIELD_OF_VIEW /2)));
	p_fov.x = (int)(p_pos.x + (p_dirr.x * scale));
	p_fov.y = (int)(p_pos.y + (p_dirr.y * scale));
	draw_square_center(img, p_fov, 5, get_rgba(100,100,100,255));
	draw_line(img, p_pos, p_fov, get_rgba(255,0,0,255));

	int             cur_w;
    t_ray           ray;
    float           cam_on_pane;
    t_player_data   p;
    
    cur_w = 0;
    p = *(d->player);
    while (cur_w <= img->width)
    {    
        cam_on_pane = 2 * cur_w / (float)img->width - 1; // why!!!!
        // ray = prepare_ray_for_dda(p, cam_on_pane);
        // putreport("prepare done");
        // printray(ray);
        // ray = dda_till_hit(ray, d->maps->maps_array);
        // putreport("DDA done\n");
        // printray(ray);
        // project_from_ray(img, ray, cur_w);
        // cur_w++;
        ray.pos.x = (int)p.pos.x;
        ray.pos.y = (int)p.pos.y;
        ray.dir.x = p.dir.x + p.pane.x * cam_on_pane;
        ray.dir.y = p.dir.y + p.pane.y * cam_on_pane;
        dprintf(2, "--------------------\nx = [%d]/[%d]\n\ncam = %f\npos = x [%d] y [%d]\nmap x = [%f]\nmap y = [%f]\n dir x [%f] y[%f]\n", cur_w, img->width,cam_on_pane, ray.pos.x,ray.pos.y,p.pos.x, p.pos.y, ray.dir.x, ray.dir.y);
        ray.delta_dis.x = abs(1 / ray.dir.x);
        if (ray.dir.x == 0)
            ray.delta_dis.x = 9999;
        ray.delta_dis.y = abs(1 / ray.dir.y);
        if (ray.dir.y == 0)
            ray.delta_dis.y = 9999;
        
        dprintf(2, "dx = [%f]\ndy = [%f]\n--------------------------\n", ray.delta_dis.x, ray.delta_dis.y);
		// ----------------------------------------------------------
		p_fov.x = (int)(p_pos.x + (ray.dir.x * scale));
		p_fov.y = (int)(p_pos.y + (ray.dir.y * scale));
		draw_line(img, p_pos ,p_fov, get_rgba(111,222,122,255));
		t_int_point delta;
		delta.x = p_pos.x;
		delta.y = (int)(d->player->pos.y + ray.delta_dis.y) * scale;
		//draw_line(img, p_pos, delta, get_rgba(255, 1 , 1 ,255));
		delta.y = p_pos.y;
		delta.x = (int)(d->player->pos.x + ray.delta_dis.x) * scale;
		//draw_line(img, p_pos, delta, get_rgba(255, 255 , 1 ,255));
		delta.x = (int)(d->player->pos.x + ray.delta_dis.x) * scale;
		delta.y = (int)(d->player->pos.y + ray.delta_dis.y) * scale;
		//draw_line(img, p_pos, delta, get_rgba(255, 255 , 1 ,255));
        // -----------------------------------------------------------

		if (ray.dir.x < 0)
		{
			ray.step_inc.x = -1;
			ray.side_dist.x = (p.pos.x - (int)p.pos.x) * ray.delta_dis.x;
		}
		else
		{
			ray.step_inc.x = 1;
			ray.side_dist.x = ((int)p.pos.x + 1.0 - (p.pos.x)) * ray.delta_dis.x;
		}
		if (ray.dir.y < 0)
		{
			ray.step_inc.y = -1;
			ray.side_dist.y = (p.pos.y - ((int)p.pos.y) * ray.delta_dis.y);
		}
		else
		{
			ray.step_inc.y = 1;
			ray.side_dist.y = ((int)p.pos.y + 1.0 - p.pos.y) * ray.delta_dis.y;
		}


		//--------------------------------------------------
		t_int_point sd;
		sd.x = (int)(p.pos.x + ray.side_dist.x) * scale;
		sd.y = p_pos.y;
		draw_line(img, p_pos, sd, get_rgba(100,100,0,255));
		sd.y = (int)(p.pos.y + ray.side_dist.y) * scale;
		sd.x = p_pos.x;
		draw_line(img, p_pos, sd, get_rgba(100,200,0,255));
		sd.y = (int)(p.pos.y + ray.side_dist.y) * scale;
		sd.x = (int)(p.pos.x + ray.side_dist.x) * scale;
		draw_line(img, p_pos, sd, get_rgba(100,200,200,255));
		//----------------------------------------------
		ray.is_hit == 0;
		while (ray.is_hit == 0)
		{
			if (ray.side_dist.x < ray.side_dist.y)
			{
				ray.side_dist.x += ray.delta_dis.x;
				ray.pos.x += ray.step_inc.x;
			}
			else
			{
				ray.side_dist.y += ray.delta_dis.y;
				ray.pos.y += ray.step_inc.y;
			}
			if (d->maps->maps_array[ray.pos.y][ray.pos.x] != '0')
				ray.is_hit == 1;
		}
		sd.y = (int)(ray.side_dist.y * scale);
		sd.x = (int)(ray.side_dist.x * scale);
		draw_line(img, p_pos, sd, get_rgba(0,0,255,255));

		cur_w++;
    }
}

static int	get_maps_scale(t_maps_data *maps_data, mlx_image_t *img)
{
	int	scale_x;
	int	scale_y;
	int	scale;

	scale_x = img->width / maps_data->maps_width;
	scale_y = img->height / maps_data->maps_height;
	if (scale_x < scale_y)
		scale = scale_x;
	else
		scale = scale_y;
	return (scale);
}

void	draw_maps(t_data *d, mlx_image_t *image, t_maps_data *maps_data)
{
	int			i;
	int			j;
	t_int_point	pos;
	int			scale;

	scale = get_maps_scale(maps_data, image);
	i = 0;
	pos.x = 0;
	while (i < maps_data->maps_width)
	{
		pos.y = 0;
		j = 0;
		while (j < maps_data->maps_height)
		{
			if (maps_data->maps_array[j][i] != FLOOR)
				draw_square(image, pos, scale - 1, get_rgba(255, 0, 0, 1000));
			else
				draw_square(image, pos, scale - 1, get_rgba(0, 0, 0, 255));
			pos.y += scale;
			j++;
		}
		pos.x += scale;
		i++;
	}
	draw_player(d, image, scale);
}
