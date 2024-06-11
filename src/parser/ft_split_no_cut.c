/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_no_cut.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 19:54:09 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/11 00:23:20 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static size_t	count_on_me(char const *s, char c)
{
	int	word;

	word = 0;
	while (*s)
	{
		if (*s == c)
			word++;
		s++;
	}
	word++;
	return (word);
}

static size_t	how_long(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
			return (count);
		count++;
		s++;
	}
	return (count);
}

char	**ft_split_no_cut(char const *s, char c)
{
	char	**resplit;
	size_t	i;
	size_t	big_i;
	int		n;

	if (!s)
		return (0);
	i = 0;
	n = 0;
	big_i = 0;
	resplit = (char **)malloc((sizeof(char *)) * (count_on_me(s, c) + 1));
	if (!resplit)
		return (0);
	while (s[i] && i <= ft_strlen(s))
	{
		if (s[i] == c)
		{
			resplit[big_i] = ft_substr(s, i - n, n + 1);
			big_i++;
			n = 0;
		}
		else
			n++;
		i++;
	}
	// printf("n is [%d] ", n);
	if (n)
	{
		resplit[big_i] = ft_substr(s, i - n, n + 1);
		big_i++;
	}
	resplit[big_i] = NULL;
	return (resplit);
}
