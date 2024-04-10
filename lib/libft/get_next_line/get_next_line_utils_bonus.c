/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:44:10 by pruenrua          #+#    #+#             */
/*   Updated: 2023/01/20 15:45:31 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	newline_checker(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			return (0);
		str++;
	}
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		i++;
		s++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*j_str;
	char	*str_joined;

	if (!s1 || !s2)
		return (0);
	j_str = malloc((ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!j_str)
		return (0);
	str_joined = j_str;
	while (*s1)
	{
		*j_str = *s1;
		s1++;
		j_str++;
	}
	while (*s2)
	{
		*j_str = *s2;
		s2++;
		j_str++;
	}
	*j_str = '\0';
	return (str_joined);
}
