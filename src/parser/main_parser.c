/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:35:07 by wave              #+#    #+#             */
/*   Updated: 2024/06/12 02:37:28 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	checklist(t_parser_data *res, char **data)
{
	if (data == NULL)
		return (free(res), 0);
	if (count_value_line(data) == -1)
		return (puterror("count value line"), free_2dwithres(res, data), 0);
	res->ceil_color = -1;
	res->floor_color = -1;
	if (!check_resource(data, res))
		return (free_2dwithres(res, data), 0);
	if (!src_checker(res))
		return (free_2dwithres(res, data), 0);
	dprintf(2, "check list done\n");
	return (1);
}

t_parser_data	*main_parser(char *file_name)
{
	t_parser_data	*res;
	int				fd;
	char			**data;

	res = ft_calloc(sizeof(t_parser_data), 1);
	if (!is_file_valid(file_name, ".cub"))
		return (free(res), NULL);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (free(res), NULL);
	data = file_reader(fd);
	close(fd);
	if (!checklist(res, data))
		return (NULL);
	res->height = find_height(data);
	res->width = find_width(data);
	if (res->height == 0 || res->width == 0)
		return (free_2dwithres(res, data), NULL);
	res->maps_data = init_map(data, res->width, res->height);
	if (!is_all_mapline(res->maps_data) || \
		!scan4player(res->maps_data) || \
		!border_checker(res, res->maps_data))
		return (free_parser(res), NULL);
	return (res);
}
