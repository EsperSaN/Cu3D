/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_of.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:41 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 16:28:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_first_of_space(char *str)
{
	int	idx;

	idx = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (true == ft_isspace(*str))
			return (idx);
		str++;
		idx++;
	}
	return (0);
}
