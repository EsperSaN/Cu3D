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

int	main(int ac, char **av)
{
	t_data	*d;

	if (ac != 2)
		return (puts(WRG_ARG_NO), 1);
	d = ft_calloc(sizeof(t_data), 1);
	if (d == NULL)
		return (1);
	(void)av;
	d->parser_data = main_parser(av[1]);
	if (prepare_render(d) == false)
		return (1);
	mlx_loop_hook(d->mlx, main_render, (void *)d);
	mlx_loop(d->mlx);
}
