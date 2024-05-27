/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putreport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:22:18 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 01:23:45 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	putreport(char *msg)
{
	write(STDERR_FILENO, "REPORT: ", 8);
	while (*msg)
	{
		write(STDERR_FILENO, msg, 1);
		msg++;
	}
	write(STDERR_FILENO, "\n", 1);
	return ;
}