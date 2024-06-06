/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:40:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/05 16:15:57 by pruenrua         ###   ########.fr       */
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
		dprintf(2, "[%s] -> %s -> %s\n", map[i], tmp[0], tmp[1]);
		dprintf(2, "here\n");
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
	if (count_value_line(data) == -1)
		return (free_2dwithres(res, data), 0);
	if (!check_resource(data, res))
		return (free_2dwithres(res, data), 0);
	if (!src_checker(res))
		return (free_2dwithres(res, data), 0);
	return (1);
}

char	*read_loop(int read_co, char *chdata, int fd, char *buffer)
{
	char	*tmp;

	while (read_co > 0)
	{
		tmp = chdata;
		read_co = read(fd, buffer, BUFFER_SIZE);
		buffer[read_co] = '\0';
		chdata = ft_strjoin(tmp, buffer);
		if ((buffer[0] < 32 || buffer[0] > 126) \
			&& buffer[0] != '\n' && read_co > 0)
			read_co = 0;
		free(tmp);
	}
	free(buffer);
	if (read_co < -1)
		perror("FILE READER : ");
	return (chdata);
}

int	is_numline(char *str)
{
	int			i;
	int			co;
	t_int_point	count;

	co = 0;
	i = 0;
	count.x = 0;
	count.y = 0;
	printf("str num is <%s>\n", str);
	while (str[i])
	{
		if (str[i] == ',')
			co++;
		else if (str[i] == 'F')
			count.x++;
		else if (str[i] == 'C')
			count.y++;
		else if (!((str[i] <= '9' && str[i] >= '0') \
			|| ft_isspace(str[i])))
			return (0);
		i++;
	}
	if (co > 2 || count.x + count.y > 1)
		return (0);
	return (1);
}
