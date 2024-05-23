/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:55:44 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 02:37:33 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

int	get_direction(float degree_angle)
{
	if (degree_angle == 0)
		return (E);
	if (degree_angle == 90)
		return (N);
	if (degree_angle == 180)
		return (W);
	if (degree_angle == 270)
		return (S);
	if (degree_angle > 0 && degree_angle < 90)
		return (NE);
	if (degree_angle > 90 && degree_angle < 180)
		return (NW);
	if (degree_angle > 180 && degree_angle < 270)
		return (SW);
	if (degree_angle > 0 && degree_angle < 90)
		return (SE);
	return (0);
}
