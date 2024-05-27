#include "free.h"

t_player_data *free_player(t_player_data *data)
{
	if (data != NULL)
	{
		//ft_memset(data, 0, sizeof(t_player_data));
		free(data);
	}
	return (NULL);
}
