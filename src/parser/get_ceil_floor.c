/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceil_floor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:21 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 22:15:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	get_ceil_floor(char *str, t_parser_data *res, char mode)
{
	int		i;
	int		color[3];
	int		rgb;
	char	**num;

	num = ft_split(str, ',');
	i = 0;
	while (num[i])
	{
		if (ft_atoi(num[i]) < 0 || ft_atoi(num[i]) > 255)
			return (free2d(num), 0);
		i++;
	}
	if (i != 3)
		return (free2d(num), 0);
	i = -1;
	while (num[++i])
		color[i] = ft_atoi(num[i]);
	rgb = get_rgba(color[0], color[1], color[2], 255);
	if (mode == 'c' && res->ceil_color == -1)
		res->ceil_color = rgb;
	else if (mode == 'f' && res->floor_color == -1)
		res->floor_color = rgb;
	free2d(num);
	return (1);
}
