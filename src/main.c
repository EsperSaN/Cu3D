/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:25:08 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/28 00:53:52 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube.h"

	// branch name/topic/feof
	// header -I

void struct_print(t_data *data)
{
	int i;
	
	i = 0;
	dprintf(2, "mlx instant ptr -> [%p]\n", data->mlx);
	dprintf(2, "img_game ptr -> [%p]\n", data->img_game);
	dprintf(2, "img_maps ptr -> [%p]\n", data->img_maps);
	dprintf(2, "NO -> [%s]\nSO -> [%s]\nWE -> [%s]\nEA -> [%s]\nF_COLOR -> [%zd]\nC_COLOR -> [%zd]\nMAP -> H : [%d] W : [%d]\n", data->parser_data->north_texture, data->parser_data->south_texture,\
					data->parser_data->west_texture, data->parser_data->east_texture,\
					data->parser_data->floor_color, data->parser_data->ceil_color,\
					data->parser_data->height, data->parser_data->width);
	dprintf(2, "---------------- MAP ------------------\n");
	while (data->parser_data->maps_data[i])
	{
		dprintf(2, "%s\n", data->parser_data->maps_data[i]);
		i++;
	}
	dprintf(2, "---------------------------------------\n");
}

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
		ft_memset(data, 0, sizeof(t_texture));
		free(data);
	}
	return (NULL);
}

t_texture_assets *free_texture_assets(t_texture_assets *data)
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
		ft_memset(data, 0, sizeof(t_texture_assets));
		free(data);
	}
	return (NULL);
}

t_player_data *free_player(t_player_data *data)
{
	if (data != NULL)
	{
		ft_memset(data, 0, sizeof(t_player_data));
		free(data);
	}
	return (NULL);
}

t_maps_data *free_maps(t_maps_data *data)
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
		ft_memset(data, 0, sizeof(t_parser_data));
		free(data);
	}
	return (NULL);
}

void terminate_and_cleanup(t_data **d_ptr)
{
	t_data *data;
	
	data = *d_ptr;
	// clean the parser struct
	if (data->parser_data != NULL)
		data->parser_data = free_parser(data->parser_data);
	if (data->maps != NULL)
		data->maps = free_maps(data->maps);
	if(data->player != NULL)
		data->player = free_player(data->player);
	// clean the texture struct
	if (data->texture != NULL)
		data->texture = free_texture_assets(data->texture);
	// clen the mlx stuff img instant blasssss
	if (data->img_game)
		mlx_delete_image(data->mlx, data->img_game);
	if (data->img_maps)
		mlx_delete_image(data->mlx, data->img_maps);
	if (data->mlx)
	{
		mlx_close_window(data->mlx);
		mlx_terminate(data->mlx);
	}
	ft_memset(data, 0, sizeof(t_data));
	free(data);
}

int	main(int ac, char **av)
{
	t_data	*d;

	if (ac != 2)
		return (puterror(WRG_ARG_NO), 1);
	d = ft_calloc(sizeof(t_data), 1);
	if (d == NULL)
		return (puterror("Malloc::faill to alloc the thing!!!"), 1);
	d->parser_data = main_parser(av[1]);
	struct_print(d);
	// gerpdata from above
	// if (d->parser_data == NULL)
	// 	return (terminate_and_cleanup(&d), 1);
	// if (prepare_render(d) == false)
	// 	return (terminate_and_cleanup(&d), 1);
	//mlx_key_hook(d->mlx, );
	//mlx_loop_hook(d->mlx, main_render, (void *)d);
	//mlx_loop(d->mlx);
	terminate_and_cleanup(&d);
	return (0);
}
