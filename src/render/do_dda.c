/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_dda.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 15:42:23 by wave              #+#    #+#             */
/*   Updated: 2024/06/03 22:05:15 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	do_dda(t_raydata *ray, char **maps)
{
	while (ray->is_hit == false)
	{
		if (ray->side_distant.x < ray->side_distant.y)
		{
			ray->side_distant.x += ray->delta_distant.x;
			ray->pos.x += ray->step.x;
			ray->hit_side = X_LINE;
		}
		else
		{
			ray->side_distant.y += ray->delta_distant.y;
			ray->pos.y += ray->step.y;
			ray->hit_side = Y_LINE;
		}
		if (maps[ray->pos.y][ray->pos.x] != '0')
			ray->is_hit = true;
	}
	if (ray->hit_side == X_LINE)
		ray->perp_wall_distant = \
			(ray->side_distant.x - ray->delta_distant.x);
	else if (ray->hit_side == Y_LINE)
		ray->perp_wall_distant = \
			(ray->side_distant.y - ray->delta_distant.y);
}
