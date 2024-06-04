/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wave <wave@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 17:34:25 by wave              #+#    #+#             */
/*   Updated: 2024/06/04 15:03:07 by wave             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

# include "cube.h"

t_texture			*free_texture(t_texture *data);
t_texture			*free_texture2(t_texture *data, int i);
t_texture_assets	*free_texture_assets(t_texture_assets *data);
t_player_data		*free_player(t_player_data *data);
t_parser_data		*free_parser(t_parser_data *data);
t_maps_data			*free_maps(t_maps_data *data);
void				terminate_and_cleanup(t_data **d_ptr);

#endif