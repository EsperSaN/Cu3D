/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:31:36 by wave              #+#    #+#             */
/*   Updated: 2024/06/02 17:32:30 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_maps_data	*free_maps(t_maps_data *data)
{
	if (data != NULL)
	{
		dprintf(2, "free maps->>>>");
		if (data->maps_array)
			free2d(data->maps_array);
		dprintf(2, "free 2d fin\n");
		ft_memset(data, 0, sizeof(t_maps_data));
		free(data);
	}
	return (NULL);
}
