/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:35:07 by wave              #+#    #+#             */
/*   Updated: 2024/06/13 00:02:13 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static int	checklist(t_parser_data *res, char **data)
{
	if (data == NULL)
		return (free(res), 0);
	if (count_value_line(data) == -1)
		return (puterror("element not equal to six"), \
				free_2dwithres(res, data), 0);
	res->ceil_color = -1;
	res->floor_color = -1;
	if (!check_resource(data, res))
		return (free_2dwithres(res, data), 0);
	putreport("get all element done");
	if (!src_checker(res))
		return (free_2dwithres(res, data), 0);
	putreport("check element done");
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
	res->maps_data = init_map(data, res->height);
	if (!is_all_mapline(res->maps_data) || \
		!scan4player(res->maps_data) || \
		!border_checker(res, res->maps_data))
		return (free_parser(res), NULL);
	return (res);
}
