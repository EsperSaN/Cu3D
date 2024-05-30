#include "free.h"

void terminate_and_cleanup(t_data **d_ptr)
{
	t_data *data;
	
	data = *d_ptr;
	// clean the parser struct
	if (data->parser_data != NULL)
		data->parser_data = free_parser(data->parser_data);
	dprintf(2, "FREE parser\n");
	if (data->maps != NULL)
		data->maps = free_maps(data->maps);
	dprintf(2, "FREE maps\n");
	if(data->player != NULL)
		data->player = free_player(data->player);
	dprintf(2, "FREE player\n");
	// clean the texture struct
	if (data->texture != NULL)
		data->texture = free_texture_assets(data->texture);
	dprintf(2, "FREE TEX\n");
	// clen the mlx stuff img instant blasssss

	if (data->img_game)
		mlx_delete_image(data->mlx, data->img_game);
	if (data->img_maps)
		mlx_delete_image(data->mlx, data->img_maps);
	dprintf(2, "FREE IMG");
	if (data->mlx)
		mlx_terminate(data->mlx);
	dprintf(2,"FREE MLX\n");
	free(data);
	// ft_memset(data, 0, sizeof(t_data));
}
