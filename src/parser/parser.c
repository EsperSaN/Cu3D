/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/04/25 18:31:54 by pruenrua         ###   ########.fr       */
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

	dprintf(2,"%s\n%s\n%s\n%s\n", res->west_texture, res->south_texture, res->north_texture, res->east_texture);
	// printf("%d %d %d %d\n", res->floor_color[0], res->floor_color[1], res->floor_color[2], res->floor_color[3]);
	// printf("%d %d %d %d\n", res->ceil_color[0], res->ceil_color[1], res->ceil_color[2], res->ceil_color[3]);
	while (res->maps_data[i])
	{
		printf("%d = {%s\n}", i ,res->maps_data[i]);
		i++;
	}
}

char	*file_reader(int fd)
{
	char	*tmp;
	char	*chdata;
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
		buffer[read_count] = '\0';
		free(tmp);
	}
	if (read_count < -1)
		perror("FILE READER : ");
	free(buffer);
	buffer = NULL;
	// map = ft_split(chdata, '\n');
	// word_cut(chdata);
	// free(chdata);
	return (chdata);
}

t_parser_data	*main_parser(char *file_name)
{
	t_parser_data	*res;
	int				fd;
	char			*data;
	char			**sp_data;
	char			*color;
	char			**sp_color;

	if (!is_file_valid(file_name, ".cub"))
		return (0);
	res = ft_calloc(sizeof(t_parser_data), 1);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);
	data = file_reader(fd);
	sp_data = ft_split(data, '\n');
	free(data);
	res->north_texture = get_texture_file(sp_data, "NO");
	res->south_texture = get_texture_file(sp_data, "SO");
	res->west_texture = get_texture_file(sp_data, "WE");
	res->east_texture = get_texture_file(sp_data, "EA");
	res->maps_data = get_maps_array(sp_data);

	color = get_texture_file(sp_data, "F");
	sp_color = ft_split(color, ',');
	res->floor_color = get_rgba(ft_atoi(sp_color[0]),\
								ft_atoi(sp_color[1]),\
								ft_atoi(sp_color[2]),\
								255);
	free(color);
	free2d(sp_color);

	color = get_texture_file(sp_data, "C");
	sp_color = ft_split(color, ',');
	res->ceil_color = get_rgba(ft_atoi(sp_color[0]),\
								ft_atoi(sp_color[1]),\
								ft_atoi(sp_color[2]),\
								255);
	free(color);
	free2d(sp_color);
	
	free2d(sp_data);
	//find height
	int	height = 0;
	int width = 0;
	int tmp = 0;
	while (res->maps_data[height])
	{
		tmp = ft_strlen(res->maps_data[height]);
		if (tmp > width)
			width = tmp;
		height++;
	}
	res->height = height;
	res->width = width;
	//find width
	//assign map value
	//free data
	//check all
	// close(fd);
	return (res);
}
