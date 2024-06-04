/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putreport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:22:18 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/04 11:26:33 by wave             ###   ########.fr       */
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
