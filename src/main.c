/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 21:25:08 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 22:00:53 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cube.h"

int	main(int ac, char **av)
{
	t_data	d;
	if (ac != 2)
		return (puts(WRG_ARG_NO), 1);

	(void)av;
	d.parser_data = main_parser(av[1]);
	//d.maps = get_data_from_parser(d.parser_data);
	d.mlx = mlx_init(SCREEN_WIDTH, SCREEN_HIGHT, "ray", false);
	
	d.img_game = mlx_new_image(d.mlx, SCREEN_WIDTH / 2, SCREEN_HIGHT);
	d.img_maps = mlx_new_image(d.mlx, SCREEN_WIDTH / 2, SCREEN_HIGHT);
	
	mlx_image_to_window(d.mlx, d.img_maps, 0, 0);
	mlx_image_to_window(d.mlx, d.img_game, SCREEN_WIDTH / 2, 0);
	
	clear_image(d.img_game, get_rgba(255, 0, 0, 255));
	clear_image(d.img_maps, get_rgba(0, 255, 0, 255));
	mlx_loop(d.mlx);
	puts("done");
	// d = init();
	// d->parser_data = data_parser(av); // do the read file
	// assign_data(d);

}
