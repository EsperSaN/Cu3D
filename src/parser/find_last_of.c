/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_last_of.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:28:55 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 16:28:56 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	find_last_of(char *str, char c)
{
	int	len;

	if (!str)
		return (-1);
	len = ft_strlen(str);
	len = len - 1;
	while (str[len])
	{
		if (str[len] == c)
			return (len);
		len--;
	}
	return (-1);
}
