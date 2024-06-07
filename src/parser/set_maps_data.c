/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_maps_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 22:31:37 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/07 14:57:16 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_maps_data	*set_maps_data(t_data *data)
{
	t_maps_data	*res;
	int			i;

	res = ft_calloc(sizeof(t_maps_data), 1);
	if (res == NULL)
		return (NULL);
	res->maps_array = ft_calloc(sizeof(char *), data->parser_data->height + 1);
	if (res->maps_array == NULL)
		return (free(res), NULL);
	i = 0;
	while (data->parser_data->maps_data[i])
	{
		res->maps_array[i] = \
				ft_strdup(data->parser_data->maps_data[i]);
		if (res->maps_array[i] == NULL)
		{
			free_maps(res);
			return (NULL);
		}
		i++;
	}
	res->maps_width = data->parser_data->width;
	res->maps_height = data->parser_data->height;
	return (res);
}
