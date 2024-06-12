/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_file_readable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:28:03 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 23:05:17 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

// just to check if the file canbe open and read

bool	is_file_readable(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	ft_putstr_fd("open ", 1);
	ft_putstr_fd(file_name, 1);
	ft_putstr_fd(" : ", 1);
	if (fd == -1)
	{
		perror("");
		return (false);
	}
	if (fd > 0)
		close(fd);
	ft_putstr_fd("OK!!\n", 1);
	return (true);
}
