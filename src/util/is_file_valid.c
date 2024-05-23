/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:34:11 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 02:34:18 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

bool	is_file_valid(char *file_name, char *extension)
{
	if (!file_name)
		return (puterror("File Error : NULL"), FALSE);
	if (extension != NULL && !is_right_extension(file_name, extension))
		return (puterror("file not the right extention"), FALSE);
	if (!is_file_readable(file_name))
		return (0);
	return (puterror("File is Valid"), TRUE);
}