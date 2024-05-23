/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 01:45:56 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 01:49:42 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "util.h"

float	ft_cos(float degree)
{
	float	radian;

	radian = get_rad(degree);
	return (cosf(radian));
}
