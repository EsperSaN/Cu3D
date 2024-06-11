/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_map_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:49 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 16:29:51 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_map_line(char *str)
{
	int	i;
	int f;

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