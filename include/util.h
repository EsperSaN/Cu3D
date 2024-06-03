/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:21:53 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/02 17:42:23 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_H
# define UTIL_H

# include "cube.h"

void			puterror(char *msg);
void			putreport(char *msg);
float			get_rad(float deg);
bool			is_same_str(char *s1, char *s2);
bool			is_right_extension(char *file_name, char *extension);
bool			is_file_readable(char *file_name);
bool			is_file_valid(char *file_name, char *extension);
int				get_rgba(int r, int g, int b, int a);
float			abs_deg(float dregree);
t_texture		*get_texture_png(char *tex_file);
void			free2d(char **ptr);
void			terminate_and_cleanup(t_data **d_ptr);
t_float_point	rotate_vector(t_float_point vec, float angle);
float			ft_cos(float degree);
float			ft_sin(float degree);
#endif
