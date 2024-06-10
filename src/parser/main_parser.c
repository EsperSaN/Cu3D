/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 12:35:07 by wave              #+#    #+#             */
/*   Updated: 2024/06/10 17:25:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	checklist(t_parser_data *res, char **data)
{
	if (data == NULL)
		return (free(res), 0);
	// if (count_value_line(data) == -1)
	// 	return (puterror("count value line"), free_2dwithres(res, data), 0);
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

	for (int i = 0; data[i]; i++)
		printf("%s\n", data[i]);

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