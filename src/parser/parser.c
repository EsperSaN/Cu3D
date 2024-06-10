/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/09 12:59:32 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	**init_map(char **smap, int width, int height)
{
	char	**map;
	int		i;

	i = 0;
	(void)width;
	map = (char **)malloc(sizeof(char *) * (height + 1));
	map[height] = NULL;
	while (i < height)
	{
		map[i] = ft_strdup(smap[i + 6]);
		i++;
	}
	free2d(smap);
	return (map);
}

char	**file_reader(int fd)
{
	char	*chdata;
	char	**map;
	char	*buffer;
	int		read_count;

	dprintf(2, "start file reader !!!\n");
	read_count = 1;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (puterror(": Fatal"), NULL);
	buffer[BUFFER_SIZE] = '\0';
	chdata = ft_calloc(sizeof(char), 1);
	if (!chdata)
		return (free(buffer), puterror(": Fatal"), NULL);
	chdata = read_loop(read_count, chdata, fd, buffer);
	// if (scanner(chdata) == 0 || !ft_strlen(chdata))
	// 	return (free(chdata), NULL);
	map = ft_split(chdata, '\n');
	free(chdata);
	return (map);
}


void	free_2dwithres(t_parser_data *res, char **data)
{
	free2d(data);
	free_parser(res);
}

void	get_texture_check(char *type, char *text, t_parser_data *res)
{
	if (is_same_str(type, "NO") && !res->north_texture)
		res->north_texture = ft_strdup(text);
	if (is_same_str(type, "SO") && !res->south_texture)
		res->south_texture = ft_strdup(text);
	if (is_same_str(type, "EA") && !res->east_texture)
		res->east_texture = ft_strdup(text);
	if (is_same_str(type, "WE") && !res->west_texture)
		res->west_texture = ft_strdup(text);
}
