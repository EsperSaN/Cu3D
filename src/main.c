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

#include "cube.h"

	// branch name/topic/feof
	// header -I

void struct_print(t_data *data)
{
	int i;
	
	i = 0;
	dprintf(2, "mlx instant ptr -> [%p]\n", data->mlx);
	dprintf(2, "img_game ptr -> [%p]\n", data->img_game);
	dprintf(2, "img_maps ptr -> [%p]\n", data->img_maps);
	dprintf(2, "NO -> [%s]\nSO -> [%s]\nWE -> [%s]\nEA -> [%s]\n", data->parser_data->north_texture, data->parser_data->south_texture,\
					data->parser_data->west_texture, data->parser_data->east_texture);
    dprintf(2, "F_COLOR -> [%d]\nC_COLOR -> [%d]\nMAP -> H : [%d] W : [%d]\n", \
				data->parser_data->floor_color, \
				data->parser_data->ceil_color,\
				data->parser_data->height, \
				data->parser_data->width);
	dprintf(2, "---------------- MAP ------------------\n");
	while (data->parser_data->maps_data[i])
	{
		dprintf(2, "%s\n", data->parser_data->maps_data[i]);
		i++;
	}
	dprintf(2, "---------------------------------------\n");
}


void hook(void *d)
{
	dprintf(2, "ha");
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
	if (d->parser_data == NULL)
		return (terminate_and_cleanup(&d), 1);
	set_from_parser_data(d);
	if (prepare_render(d) == false)
	 	return (terminate_and_cleanup(&d), 1);
	//mlx_key_hook(d->mlx, );
	//mlx_loop_hook(d->mlx, main_render, (void *)d);
	// mlx_loop_hook(d->mlx, hook, NULL);
	// mlx_loop(d->mlx);
	terminate_and_cleanup(&d);
	return (0);
}
