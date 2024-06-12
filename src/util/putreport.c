/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putreport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:22:18 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/12 18:30:11 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

void	putreport(char *msg)
{
	write(STDOUT_FILENO, "REPORT: ", 8);
	while (*msg)
	{
		write(STDOUT_FILENO, msg, 1);
		msg++;
	}
	write(STDOUT_FILENO, "\n", 1);
	return ;
}
