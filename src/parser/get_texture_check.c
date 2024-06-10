/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 15:10:32 by tpoungla          #+#    #+#             */
/*   Updated: 2024/06/10 16:07:19 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void	get_texture_check(char *type, char *text, t_parser_data *res)
{
	if (is_same_str(type, "NO") && !res->north_texture)
		res->north_texture = ft_strdup(text);
	if (is_same_str(type, "SO") && !res->south_texture)
		res->south_texture = ft_strdup(text);
	if (is_same_str(type, "EA") && !res->east_texture)
		res->east_texture = ft_strdup(text);
	if (is_same_str(type, "WE") && !res->west_texture)
		res->west_texture = ft_strdup(text);
}
