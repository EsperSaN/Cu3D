/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:23:39 by pruenrua          #+#    #+#             */
/*   Updated: 2024/04/12 02:51:12 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// SETTING

# define SCREEN_HIGHT 400
# define SCREEN_WIDTH  400
# define FIELD_OF_VIEW 60
# define WIN_TITLE "RAY CASTING"
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.5

// DONT CHANGE
# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL 0
# define PI 3.14123456789098765432123456789876543212345678909876543f
# define FLOOR '0'
# define WALL '1'

// error msg

#define BAD_DEFINE "I WON'T LET YOU MESS WITH THE SETTING!!!!"
#define WRG_ARG_NO "Invalid arguments number!"

enum	e_direction
{
	N = 0,
	E,
	S,
	W,
	NE,
	NW,
	SE,
	SW
};

typedef struct s_texture_data
{
	int				width;
	int				height;
	unsigned int	**pixel_array;
}	t_texture;

typedef struct s_texture
{
	//get_png_texture to assign this
	t_texture		*west_texture;
	t_texture		*east_texture;
	t_texture		*north_texture;
	t_texture		*south_texture;

	// get_rgb to assign this
	unsigned int	floor_color;
	unsigned int	ceil_color;
}	t_texture_assets;

typedef struct s_maps_data
{
	char		**maps_ar;
	int			maps_width;
	int			maps_height;
}	t_maps_data;

typedef struct s_parser_raw_data
{
	// check the file and str not above
	char	*west_texture;
	char	*east_texture;
	char	*north_texture;
	char	*south_texture;
	int		floor_color[4];
	int		ceil_color[4];
	char	**maps_data;
}	t_parser_data;

typedef struct s_player_data
{
	float	pos_x;
	float	pos_y;
	float	angle;
}	t_player_data;

typedef struct s_data
{
	t_parser_data		*parser_data;
	// check file before assign
	t_texture_assets	*texture;
	//ff before maps
	t_maps_data			*maps;
	t_player_data		*player;
}	t_data;

#endif