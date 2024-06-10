/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:31:03 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/09 12:29:33 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		printf("[");
		while (map[i][j])
		{
			printf("%c", map[i][j]);
			j++;
		}
		printf("]\n");
		i++;
	}
}

void	print_map_data(t_parser_data *res)
{
	if (res->north_texture)
		printf("NO : [%s]\n", res->north_texture);
	if (res->south_texture)
		printf("SO : [%s]\n", res->south_texture);
	if (res->west_texture)
		printf("WE : [%s]\n", res->west_texture);
	if (res->east_texture)
		printf("EA : [%s]\n", res->east_texture);
	if (res->floor_color)
		printf("floor : [%u]\n", res->floor_color);
	if (res->ceil_color)
		printf("ceil : [%u]\n", res->ceil_color);
}
