#include "free.h"

t_maps_data *free_maps(t_maps_data *data)
{
	if (data != NULL)
	{
		dprintf(2,"free maps->>>>");
		// for(int i = 0; data->maps_array[i]; i++)
		// 	dprintf(2, ">>> [%p] >>> [%s] <<<<\n", data->maps_array[i], data->maps_array[i]);
		if (data->maps_array)
			free2d(data->maps_array);
		dprintf(2, "free 2d fin\n");
		ft_memset(data, 0, sizeof(t_maps_data));
		free(data);
	}
	return (NULL);
}