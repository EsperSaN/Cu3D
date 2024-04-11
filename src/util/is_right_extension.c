/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:26:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 02:33:31 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./util.h"

// to check for the last file extention consider the filename.txt.cub

bool	is_right_extension(char *file_name, char *extension)
{
	if (!is_same_str(extension, ft_strrchr(file_name, '.')))
		return (FALSE);
	return (TRUE);
}
