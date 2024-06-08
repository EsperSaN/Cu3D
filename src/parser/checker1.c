/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 08:50:50 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/07 23:05:47 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int	is_map_element(char c)
{
	if (c == 'S' || c == 'W' || c == 'E' \
		|| c == 'N' || c == '0' || c == '1' || c == ' ')
		return (1);
	return (0);
}

int	is_map_not_sp(char c)
{
	if (c == 'S' || c == 'W' || c == 'E' \
		|| c == 'N' || c == '0' || c == '1')
		return (1);
	return (0);
}

int	ft_isspace(char c)
{
	if (c == '\r' || c == '\n' || c == '\f' )
		return (1);
	else if (c == '\v' || c == '\t' || c == ' ' )
		return (1);
	return (0);
}

int	in_line(char *str, int start, int stop)
{
	int	i;
	int	f;

	f = 0;
	i = start;
	if (start == stop)
		return (0);
	while (i < stop)
	{
		if (!ft_isspace(str[i]))
			f++;
		i++;
	}
	if (f == 0)
		return (0);
	i = start;
	while (i < stop)
	{
		if (!is_map_element(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_isprint_mk2(int c)
{
	if ((c >= ' ' && c <= '~') || ft_isspace(c))
		return (1);
	else
		return (0);
}

int	scanner(char *data)
{
	int	i;
	int	num[4];
	bool	isnt_print;

	isnt_print = false;
	i = -1;
	while (i < 4)
		num[i++] = 0;
	i = 0;
	while (data[i])
	{
		// if (false == ft_isprint_mk2(data[i]))
		// {
		// 	isnt_print = true;
		// 	dprintf(2, "the [%c] true\n", data[i]);
		// }
		if (data[i] == '\n')
		{
			num[1] += scanner_checker (num, i, data);
			num[0] = in_line(data, i - num[2] + num[3], i);
			num[2] = 0;
			num[3] = 1;
		}
		num[2]++;
		i++;
	}
	num[1] += scanner_checker (num, i, data);
	num[0] = in_line(data, i - num[2] + num[3], i);
	if ((num[0] + num[1]) > 1)
		return (0);
	return (1);
}
