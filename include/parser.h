/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:14:51 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 00:07:23 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cube.h"

char				**init_map(char **smap, int height);
char				**file_reader(int fd);
t_parser_data		*main_parser(char *file_name);
char				*get_texture_file(char **map, char *indicater);
int					find_height(char **data);
int					find_width(char **data);
int					count_value_line(char **data);
int					check_resource(char **map, t_parser_data *res);
int					get_ceil_floor(char *str, t_parser_data *res, char mode);
int					src_checker(t_parser_data *res);
int					scan4player(char **map);
int					border_checker(t_parser_data *data, char **map);
int					is_map_not_sp(char c);
void				free_2dwithres(t_parser_data *res, char **data);
int					get_element_check(char *type, char *text, \
						t_parser_data *res);
char				**ft_floodfill(t_parser_data *data);
bool				set_from_parser_data(t_data *data);
t_maps_data			*set_maps_data(t_data *data);
t_texture_assets	*set_texture_assets(t_data *data);
char				*read_loop(int read_co, char *chdata, int fd, \
						char *buffer);
int					is_map_element(char c);
int					is_numline(char *str);
int					ft_isspace(char c);
int					ft_isprint_mk2(int c);
char				**ft_split_no_cut(char const *s, char c);
int					is_map_line(char *str);
int					is_all_mapline(char **data);
int					find_first_mapline(char **data);
int					find_first_of_space(char *str);
int					find_last_of(char *str, char c);
#endif