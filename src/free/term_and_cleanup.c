/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_and_cleanup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 11:30:41 by wave              #+#    #+#             */
/*   Updated: 2024/06/04 11:32:21 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	terminate_and_cleanup(t_data **d_ptr)
{
	t_data	*data;

	data = *d_ptr;
	if (data->parser_data != NULL)
		data->parser_data = free_parser(data->parser_data);
	if (data->maps != NULL)
		data->maps = free_maps(data->maps);
	if (data->player != NULL)
		data->player = free_player(data->player);
	if (data->texture != NULL)
		data->texture = free_texture_assets(data->texture);
	if (data->img_game)
		mlx_delete_image(data->mlx, data->img_game);
	if (data->img_maps)
		mlx_delete_image(data->mlx, data->img_maps);
	if (data->mlx)
		mlx_terminate(data->mlx);
	free(data);
}
