/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_maps_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:31:36 by wave              #+#    #+#             */
/*   Updated: 2024/06/07 14:57:18 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

t_maps_data	*free_maps(t_maps_data *data)
{
	if (data != NULL)
	{
		if (data->maps_array)
			free2d(data->maps_array);
		ft_memset(data, 0, sizeof(t_maps_data));
		free(data);
	}
	return (NULL);
}
