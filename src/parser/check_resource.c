/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:22 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 17:23:51 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

// check and get resouce element [C F N S NA WE] and assign to the res struct 
// should try to search until hit the maps region "10" && isspace maps
// -->> allow pass only the isspace on start str and end str && the empty line (all isspace line )
// if element not complete yet and the line is now allow as above ^^ this function sent false
// other wise true

int	check_resource(char **map, t_parser_data *res)
{
	int		i;
	int		j;
	char	*element[3];
	char	*tmp;

	element[2] = NULL;
	i = 0;
	dprintf(2, "\n\n\ncheck_resouse\n");
	// for each element
	while (i < 6)
	{
		dprintf(2, "\n map [%d] is [%s]\n", i, map[i]);
		tmp = map[i];
		map[i] = ft_strtrim(map[i], " \t\r\v\f");
		dprintf(2, "1st trim is [%s]\n", map[i]);
		free(tmp);
		int size_to_get = ft_strlen(map[i]) - find_first_of_space(map[i]);
		dprintf(2, "2st trim is [%s  %d]\n", map[i], size_to_get);

		element[0] = ft_substr(map[i], 0, find_first_of_space(map[i]));
		
		dprintf(2, "element[0] -> %s -> sub [%d] and [%d]\n", element[0], find_first_of_space(map[i]),size_to_get);
		
		element[1] = ft_substr(map[i], find_first_of_space(map[i]), size_to_get);
		
		dprintf(2, "element[1] -> %s\n", element[1]);
		
		tmp = element[1];
		element[1] = ft_strtrim(element[1], " \t\r\v\f");
		free(tmp);
		
		dprintf(2, "after -> [trim is s ->  [%s] -> [%s]]\n", element[0], element[1]);
		// should not be here
		i++;
		get_texture_check(element[0], element[1], res);
		if (is_same_str(element[0], "C") && is_numline(element[1]))
			get_ceil_floor(element[1], res, 'c');
		if (is_same_str(element[0], "F") && is_numline(element[1]))
			get_ceil_floor(element[1], res, 'f');
	
		free(element[0]);
		free(element[1]);
	}
	dprintf(2, "check end\n");
	return (true);
}
