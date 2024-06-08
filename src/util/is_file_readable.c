/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_readable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:28:03 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/07 19:58:12 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

// just to check if the file canbe open and read

bool	is_file_readable(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	dprintf(2 ,"open [%s] fd is [%d]\n", file_name, fd);
	if (fd == -1)
		return (false);
	if (fd > 0)
		close(fd);
	return (true);
}
