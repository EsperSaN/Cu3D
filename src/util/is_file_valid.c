/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:34:11 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/04 11:26:17 by wave             ###   ########.fr       */
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
