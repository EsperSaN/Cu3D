/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:14:51 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/10 22:15:32 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../cube.h"
# define BUFFER_SIZE 1

t_parser_data	*init_map(t_parser_data *data, int width, int height);
void			print_map(char **map);
void			print_map_data(t_parser_data *res);
char			**file_reader(int fd);
t_parser_data	*main_parser(char *file_name);

#endif