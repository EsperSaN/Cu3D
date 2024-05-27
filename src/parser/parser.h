/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:14:51 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/21 21:33:56 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cube.h"
# define BUFFER_SIZE 1

char	        **init_map(char **smap, int width, int height);
void			print_map(char **map);
void			print_map_data(t_parser_data *res);
char			**file_reader(int fd);
t_parser_data	*main_parser(char *file_name);
char			*get_texture_file(char **map, char *indicater);
char			**get_maps_array(char **maps);
int             find_height(char **data);
int             find_width(char **data);
int             scanner(char *data);
int             count_value_line(char **data);
int             check_resource(char **map, t_parser_data *res);
int             get_ceil_floor(char *str, t_parser_data *res, char mode);
int             src_checker(t_parser_data *res);
void            free_texture(t_parser_data *res);
int             scan4player(char **map);
int             border_checker(char **map);
int             is_map_element_not_sp(char c);

#endif