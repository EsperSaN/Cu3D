/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:35:07 by wave              #+#    #+#             */
/*   Updated: 2024/06/09 12:44:39 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_data	*main_parser(char *file_name)
{
	t_parser_data	*res;
	int				fd;
	char			**data;

	res = ft_calloc(sizeof(t_parser_data), 1);
	dprintf(2, "check if the [%s] is valid : ", file_name);
	if (!is_file_valid(file_name, ".cub"))
		return (free(res), NULL);
	dprintf(2, "[%s] is valid!!!\n", file_name);
	dprintf(2, "open [%s] : ", file_name);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (free(res), NULL);
	dprintf(2, "Done !!!\n");
	data = file_reader(fd);
	close(fd);
	dprintf(2, "file reader done!!\n");
	if (!checklist(res, data))
		return (NULL);
	res->height = find_height(data);
	res->width = find_width(data);
	if (res->height == 0 || res->width == 0)
		return (free_2dwithres(res, data), NULL);
	res->maps_data = init_map(data, find_width(data), find_height(data));
	if (!scan4player(res->maps_data))
		return (free_parser(res), NULL);
	if (!border_checker(res, res->maps_data))
		return (free_parser(res), NULL);
	return (res);
}