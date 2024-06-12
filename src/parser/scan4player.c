/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan4player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 16:30:13 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 00:17:40 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static void	print_player(int x, int y, char c)
{
	char	*str;

	ft_putstr_fd("Player found on ", 1);
	ft_putstr_fd("( ", 1);
	str = ft_itoa(x);
	ft_putstr_fd(str, 1);
	free(str);
	ft_putstr_fd(" , ", 1);
	str = ft_itoa(y);
	ft_putstr_fd(str, 1);
	free(str);
	ft_putstr_fd(" )", 1);
	ft_putstr_fd(" with ", 1);
	ft_putchar_fd(c, 1);
	ft_putstr_fd(" direction\n", 1);
}

int	scan4player(char **map)
{
	int	i;
	int	j;
	int	co;

	i = 0;
	co = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'W' || map[i][j] == 'N' || \
					map[i][j] == 'E' || map[i][j] == 'S')
			{
				print_player(j, i, map[i][j]);
				co++;
			}
			j++;
		}
		i++;
	}
	if (co > 1 || co == 0)
		return (ft_putstr_fd("Mutiple or none player found!!!\n", 1), 0);
	return (1);
}
