/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:26:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/05 15:54:14 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

// to check for the last file extention consider the filename.txt.cub

bool	is_right_extension(char *file_name, char *extension)
{
	if (!is_same_str(extension, ft_strrchr(file_name, '.')))
		return (false);
	return (true);
}
