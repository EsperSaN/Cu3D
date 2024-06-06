/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:14:51 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/05 14:26:50 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "cube.h"
# define BUFFER_SIZE 1

char				**init_map(char **smap, int width, int height);
void				print_map(char **map);
void				print_map_data(t_parser_data *res);
char				**file_reader(int fd);
t_parser_data		*main_parser(char *file_name);
char				*get_texture_file(char **map, char *indicater);
int					find_height(char **data);
int					find_width(char **data);
int					scanner(char *data);
int					count_value_line(char **data);
int					check_resource(char **map, t_parser_data *res);
int					get_ceil_floor(char *str, t_parser_data *res, char mode);
int					src_checker(t_parser_data *res);
int					scanner_checker(int num[], int i, char *data);
int					scan4player(char **map);
int					border_checker(t_parser_data *data, char **map);
int					is_map_not_sp(char c);
void				free_2dwithres(t_parser_data *res, char **data);
void				get_texture_check(char *type, char *text, \
						t_parser_data *res);
char				**ft_floodfill(t_parser_data *data);
t_int_point			get_player_pos4(char **map);
char				**create_visitmap(int w, int h);
void				ft_floodfill_util(t_parser_data *data, \
						char **visited, int x, int y);
t_float_point		find_player_pos(char **maps);
bool				set_from_parser_data(t_data *data);
t_maps_data			*set_maps_data(t_data *data);
t_texture_assets	*set_texture_assets(t_data *data);
int					checklist(t_parser_data *res, char **data);
char				*read_loop(int read_co, char *chdata, int fd, \
						char *buffer);
int					is_map_element(char c);
int					in_line(char *str, int start, int stop);
int					try_get_texture(t_texture_assets *res);
int					is_numline(char *str);
int					ft_isspace(char c);

#endif