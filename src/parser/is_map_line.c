/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:49 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 23:50:23 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_map_line(char *str)
{
	int	i;
	int	f;

	f = 0;
	i = 0;
	while (str[i])
	{
		if (!is_map_element(str[i]))
			return (1);
		if (str[i] == '0' || str[i] == '1')
			f = -1;
		i++;
	}
	return (f);
}

int	is_all_mapline(char **data)
{
	int	i;

	ft_putstr_fd("check maping..\n", 1);
	i = 0;
	while (data[i])
	{
		if (data[i] && 1 == is_map_line(data[i]))
			return (ft_putstr_fd(data[i], 1) \
				, ft_putstr_fd("<<< not good\n", 1), 0);
		ft_putstr_fd(data[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putstr_fd("checkmaps done!!!\n", 1);
	return (1);
}
