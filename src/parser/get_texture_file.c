/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:40:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/09 12:54:15 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

char	*get_texture_file(char **map, char *indicater)
{
	int		i;
	char	**tmp;
	char	*ret;

	i = 0;
	while (map[i])
	{
		tmp = ft_split(map[i], ' ');
		if (tmp != NULL && is_same_str(tmp[0], indicater) && tmp[1] != NULL)
		{
			ret = ft_strdup(tmp[1]);
			free2d(tmp);
			return (ret);
		}
		free2d(tmp);
		tmp = NULL;
		i++;
	}
	return (NULL);
}

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
		if (false == ft_isprint_mk2(buffer[0]))
			read_co = 0;
		free(tmp);
	}
	free(buffer);
	dprintf(2, "read is \n################\n%s\n##############\nreturn\n", chdata);
	if (read_co < -1)
		perror("FILE READER : ");
	
	return (chdata);
}

int	is_numline(char *str)
{
	int			i;
	int			co;

	co = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ',')
			co++;
		else if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	if (co > 2)
		return (0);
	dprintf(2, "[%s] << pass numline \n", str);
	return (1);
}
