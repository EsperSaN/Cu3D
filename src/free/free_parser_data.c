#include "free.h"

t_parser_data *free_parser(t_parser_data *data)
{
	if (data != NULL)
	{
		if (data->maps_data)
			free2d(data->maps_data);
		if (data->east_texture)
			free(data->east_texture);
		if (data->north_texture)
			free(data->north_texture);
		if (data->south_texture)
			free(data->south_texture);
		if (data->west_texture)
			free(data->west_texture);
		//ft_memset(data, 0, sizeof(t_parser_data));
		free(data);
	}
	return (NULL);
}