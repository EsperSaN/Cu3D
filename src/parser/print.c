/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 21:31:03 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/02 21:31:03 by tpoungla         ###   ########.fr       */
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
	printf("NO : [%s]\n", res->north_texture);
	printf("SO : [%s]\n", res->south_texture);
	printf("WE : [%s]\n", res->west_texture);
	printf("EA : [%s]\n", res->east_texture);
	printf("floor : [%u]\n", res->floor_color);
	printf("ceil : [%u]\n", res->ceil_color);
}
