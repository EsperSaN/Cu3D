/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpoungla <tpoungla@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-06-10 12:00:11 by tpoungla          #+#    #+#             */
/*   Updated: 2024-06-10 12:00:11 by tpoungla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*read_loop(int read_co, char *chdata, int fd, char *buffer)
{
	char	*tmp;
	dprintf(2, "start read loop!!!\n");
	while (read_co > 0)
	{
		tmp = chdata;
		read_co = read(fd, buffer, BUFFER_SIZE);
		buffer[read_co] = '\0';
		chdata = ft_strjoin(tmp, buffer);
		if (!chdata)
			return (puterror(": Fatal"), free(buffer), free(tmp), NULL);
		// new check will read until the non printable char are occur and '\0'
		// deprecate from
		// vvvvvvvv
		// if ((buffer[0] < 32 || buffer[0] > 126) \
		// 	&& buffer[0] != '\n' && read_co > 0)
		// 	read_co = 0;
		// if (false == ft_isprint_mk2(buffer[0]))
		// 	read_co = 0;
		free(tmp);
	}
	free(buffer);
	dprintf(2, "read is \n################\n%s\n##############\nreturn\n", chdata);
	if (read_co < -1)
		perror("FILE READER : ");
	
	return (chdata);
}

char	*file_reader(int fd)
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
	return (chdata);
}

t_parser_data	*main_parser(char *file_name)
{
	t_parser_data	*res;
	int				fd;
	char			*data;

	res = malloc(sizeof(t_parser_data) * 1);
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
	
	return (res);
}
