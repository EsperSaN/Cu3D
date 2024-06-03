/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_texture_assets.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:33:19 by wave              #+#    #+#             */
/*   Updated: 2024/06/02 17:33:38 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_texture_assets	*free_texture_assets(t_texture_assets *data)
{
	if (data != NULL)
	{
		if (data->west_texture)
			free_texture(data->west_texture);
		if (data->east_texture)
			free_texture(data->east_texture);
		if (data->north_texture)
			free_texture(data->north_texture);
		if (data->south_texture)
			free_texture(data->south_texture);
		free(data);
	}
	return (NULL);
}
