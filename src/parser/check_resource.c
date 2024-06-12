/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:22 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 00:00:47 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	get_resource(char **map, t_parser_data *res, int *elm_count)
{
	int		i;
	char	*element[3];
	char	*tmp;
	int		size_to_get;

	element[2] = NULL;
	i = 0;
	while (map[i] && is_map_line(map[i]) != -1)
	{
		element[0] = ft_strtrim(map[i], " cn\t\r\v\f");
		size_to_get = ft_strlen(element[0]) - find_first_of_space(element[0]);
		tmp = element[0];
		element[0] = ft_substr(element[0], 0, find_first_of_space(element[0]));
		element[1] = ft_substr(tmp, find_first_of_space(tmp), size_to_get);
		free(tmp);
		tmp = element[1];
		element[1] = ft_strtrim(element[1], " \n\t\r\v\f");
		free(tmp);
		*elm_count += get_element_check(element[0], element[1], res);
		free(element[0]);
		free(element[1]);
		i++;
	}
}

int	check_resource(char **map, t_parser_data *res)
{
	int	elm_count;

	elm_count = 0;
	get_resource(map, res, &elm_count);
	if (elm_count != 6)
		return (puterror("Map element are not good"), false);
	return (true);
}
