/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_same_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:13:36 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 01:16:48 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

bool	is_same_str(char *s1, char *s2)
{
	bool	ret;

	ret = TRUE;
	if (!s1 || !s2)
		return (FALSE);
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (*s1 != *s2)
			ret = FALSE;
		s2++;
		s1++;
	}
	if (*s1 != '\0' || *s2 != '\0')
		ret = FALSE;
	return (ret);
}
