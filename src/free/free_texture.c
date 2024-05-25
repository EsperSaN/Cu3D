#include "free.h"

t_texture *free_texture(t_texture *data)
{
	int		height;

	height = 0;
	if (data != NULL)
	{
		while (height < data->height)
		{
			free(data->pixel_array[height]);
			data->pixel_array[height] = NULL;
			height++;
		}
		free(data->pixel_array);
		//ft_memset(data, 0, sizeof(t_texture));
		free(data);
	}
	return (NULL);
}
