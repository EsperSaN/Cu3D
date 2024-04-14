/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <tpoungla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024-04-13 15:10:32 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_parser_data	*init_map(t_parser_data *data, int width, int height)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (height + 1));
	map[height] = NULL;
	while (map[i])
	{
		map[i] = malloc(sizeof(char) * (width + 1));
		map[i][width] = '\0';
		i++;
	}
	data->maps_data = map;
	return (data);
}

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
}

void	print_map_data(t_parser_data *res)
{
	int				i;

	i = 0;

	printf("%s\n%s\n%s\n%s\n", res->west_texture, res->south_texture, res->north_texture, res->east_texture);
	printf("%d %d %d %d\n", res->floor_color[0], res->floor_color[1], res->floor_color[2], res->floor_color[3]);
	printf("%d %d %d %d\n", res->ceil_color[0], res->ceil_color[1], res->ceil_color[2], res->ceil_color[3]);
	while (res->maps_data[i])
	{
		printf("i = {%s\n}",res->maps_data[i]);
		i++;
	}
}

char	**file_reader(int fd)
{
	char	*tmp;
	char	*chdata;
	char	**map;
	char	*buffer;
	int		read_count;

	read_count = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	buffer[BUFFER_SIZE] = '\0';
	chdata = ft_calloc(sizeof(char), 1);
	while (read_count > 0)
	{
		tmp = chdata;
		read_count = read(fd, buffer, BUFFER_SIZE);
		chdata = ft_strjoin(tmp, buffer);
		free(tmp);
	}
	if (read_count < -1)
		perror("FILE READER : ");
	map = ft_split(chdata, '\n');
	free(chdata);
	return (map);
}

t_parser_data	*main_parser(char *file_name)
{
	t_parser_data	*res;
	int				fd;
	char			**map;

	res = ft_calloc(sizeof(t_parser_data), 1);
	init_map(res, 3, 3);
	print_map_data(res);
	if (!is_file_valid(file_name, ".cub"))
		return (0);
	else
	{
		fd = open(file_name, O_RDONLY | O_CLOEXEC);
		if (fd < 0)
			return (perror("PARSER ERROR : "), NULL);
		map = file_reader(fd);
	}
	print_map(map);
	return (res);
}
