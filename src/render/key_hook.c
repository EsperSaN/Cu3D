/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:51:10 by wave              #+#    #+#             */
/*   Updated: 2024/06/12 23:58:05 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

static void	player_rotate(t_data *d, int dir)
{
	if (dir == LEFT)
	{
		d->player->dir = rotate_vector(d->player->dir, (ROT_SPEED * -1));
		d->player->pane = rotate_vector(d->player->pane, (ROT_SPEED * -1));
	}
	if (dir == RIGHT)
	{
		d->player->dir = rotate_vector(d->player->dir, (ROT_SPEED));
		d->player->pane = rotate_vector(d->player->pane, (ROT_SPEED));
	}
}

static void	player_sidemove(t_data *d, int dir)
{
	t_float_point	mdr;
	char			**maps;

	maps = d->maps->maps_array;
	mdr.x = d->player->dir.x * (MOVE_SPEED / 2);
	mdr.y = d->player->dir.y * (MOVE_SPEED / 2);
	if (dir == LEFT)
	{
		if (maps[(int)(d->player->pos.y - mdr.x)][(int)d->player->pos.x] == '0')
			d->player->pos.y -= mdr.x;
		if (maps[(int)d->player->pos.y][(int)(d->player->pos.x + mdr.y)] == '0')
			d->player->pos.x += mdr.y;
	}
	if (dir == RIGHT)
	{
		if (maps[(int)(d->player->pos.y + mdr.x)][(int)d->player->pos.x] == '0')
			d->player->pos.y += mdr.x;
		if (maps[(int)d->player->pos.y][(int)(d->player->pos.x - mdr.y)] == '0')
			d->player->pos.x -= mdr.y;
	}
}

static void	player_move(t_data *d, int dir)
{
	t_float_point	mdr;
	char			**maps;

	maps = d->maps->maps_array;
	mdr.x = d->player->dir.x * (MOVE_SPEED / 2);
	mdr.y = d->player->dir.y * (MOVE_SPEED / 2);
	if (dir == FORWARD)
	{
		if (maps[(int)(d->player->pos.y + mdr.y)][(int)d->player->pos.x] == '0')
			d->player->pos.y += mdr.y;
		if (maps[(int)d->player->pos.y][(int)(d->player->pos.x + mdr.x)] == '0')
			d->player->pos.x += mdr.x;
	}
	if (dir == BACKWARD)
	{
		if (maps[(int)(d->player->pos.y - mdr.y)][(int)d->player->pos.x] == '0')
			d->player->pos.y -= mdr.y;
		if (maps[(int)d->player->pos.y][(int)(d->player->pos.x - mdr.x)] == '0')
			d->player->pos.x -= mdr.x;
	}
}

void	key_hook(void *data)
{
	t_data	*d;

	d = data;
	if (mlx_is_key_down(d->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(d->mlx);
	if (mlx_is_key_down(d->mlx, MLX_KEY_W))
		player_move(d, FORWARD);
	if (mlx_is_key_down(d->mlx, MLX_KEY_S))
		player_move(d, BACKWARD);
	if (mlx_is_key_down(d->mlx, MLX_KEY_A))
		player_sidemove(d, LEFT);
	if (mlx_is_key_down(d->mlx, MLX_KEY_D))
		player_sidemove(d, RIGHT);
	if (mlx_is_key_down(d->mlx, MLX_KEY_LEFT))
		player_rotate(d, LEFT);
	if (mlx_is_key_down(d->mlx, MLX_KEY_RIGHT))
		player_rotate(d, RIGHT);
	main_render((void *)data);
}
