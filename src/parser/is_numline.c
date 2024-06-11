/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_numline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:29:57 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/10 16:29:58 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_numline(char *str)
{
	int			i;
	int			co;

	co = 0;
	i = 0;
	printf("try numline <%s>\n", str);
	while (str[i])
	{
		if (str[i] == ',')
			co++;
		else if ((str[i] > '9' || str[i] < '0') && !ft_isspace(str[i]))
			return (0);
		i++;
	}
	if (co > 2)
		return (0);
	dprintf(2, "[%s] << pass numline \n", str);
	return (1);
}
