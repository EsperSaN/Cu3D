/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:37:13 by wave              #+#    #+#             */
/*   Updated: 2024/06/05 15:56:05 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	find_side_step_for_dda(t_raydata *ray, t_player_data *play_data)
{
	if (ray->ray_dir.x < 0)
	{
		ray->step.x = -1;
		ray->side_distant.x = \
			(play_data->pos.x - ray->pos.x) * ray->delta_distant.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_distant.x = \
			(ray->pos.x + 1.0 - play_data->pos.x) * ray->delta_distant.x;
	}
	if (ray->ray_dir.y < 0)
	{
		ray->step.y = -1;
		ray->side_distant.y = \
			(play_data->pos.y - ray->pos.y) * ray->delta_distant.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_distant.y = \
			(ray->pos.y + 1.0 - play_data->pos.y) * ray->delta_distant.y;
	}
}

void	init_ray(t_raydata *ray, t_player_data *play_data)
{
	ray->pos.x = (int)play_data->pos.x;
	ray->pos.y = (int)play_data->pos.y;
	ray->is_hit = false;
	ray->ray_dir.x = play_data->dir.x + play_data->pane.x * ray->camera.x;
	ray->ray_dir.y = play_data->dir.y + play_data->pane.y * ray->camera.x;
	if (ray->ray_dir.x == 0)
		ray->ray_dir.x = 1e30;
	if (ray->ray_dir.y == 0)
		ray->ray_dir.y = 1e30;
	ray->delta_distant.x = fabs(1 / ray->ray_dir.x);
	ray->delta_distant.y = fabs(1 / ray->ray_dir.y);
	find_side_step_for_dda(ray, play_data);
}
