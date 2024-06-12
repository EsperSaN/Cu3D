/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_right_extension.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:26:29 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 23:09:30 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

// to check for the last file extention consider the filename.txt.cub

bool	is_right_extension(char *file_name, char *extension)
{
	if (!is_same_str(extension, ft_strrchr(file_name, '.')))
	{
		ft_putstr_fd(file_name, 1);
		ft_putstr_fd(" : not right extention!!!\n", 1);
		return (false);
	}
	return (true);
}
