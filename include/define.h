/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 22:23:39 by pruenrua          #+#    #+#             */
/*   Updated: 2024/06/13 00:12:21 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

// SETTING

# define FIELD_OF_VIEW 66
# define MOVE_SPEED 0.4
# define ROT_SPEED 2

// DONT CHANGE
# define X_LINE 0
# define Y_LINE 1
# define PI 3.14123456789098765432123456789876543212345678909876543f
# define FLOOR '0'
# define WALL '1'
# define MLX_INIT_FAIL "MLX INIT FAIL : EXIT"
# define MLX_IMG_FAIL  "MLX FAIL TO CREATE IMG"
# define BAD_DEFINE "I WON'T LET YOU MESS WITH THE SETTING!!!!"
# define WRG_ARG_NO "Invalid arguments number!"
# define READ_SIZE 1

enum	e_direction
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

typedef struct s_point_int
{
	int	x;
	int	y;
}	t_int_point;

typedef struct s_point_float
{
	float	x;
	float	y;
}	t_float_point;

typedef struct s_texture_data
{
	int				width;
	int				height;
	unsigned int	**pixel_array;
}	t_texture;

typedef struct s_draw_tex
{
	float		wall_cor_x;
	int			tex_cor_x;
	float		step_tex;
	int			color;
	t_texture	*texture;
}	t_dtex;

typedef struct s_texture
{
	t_texture		*west_texture;
	t_texture		*east_texture;
	t_texture		*north_texture;
	t_texture		*south_texture;
	unsigned int	floor_color;
	unsigned int	ceil_color;
}	t_texture_assets;

typedef struct s_maps_data
{
	char		**maps_array;
	int			maps_width;
	int			maps_height;
}	t_maps_data;

typedef struct s_parser_raw_data
{
	char	*west_texture;
	char	*east_texture;
	char	*north_texture;
	char	*south_texture;
	int		floor_color;
	int		ceil_color;
	int		height;
	int		width;
	char	**maps_data;
}	t_parser_data;

typedef struct s_drawmaps
{
	t_int_point	pos;
	t_int_point	cur_p;
	t_int_point	draw;
	int			scale;

}	t_dm;

typedef struct s_player_data
{
	t_float_point	pos;
	t_float_point	dir;
	t_float_point	pane;
	float			angle;
}	t_player_data;

typedef struct s_ray_data
{
	t_float_point		camera;
	t_float_point		ray_dir;
	t_float_point		side_distant;
	t_float_point		delta_distant;
	t_int_point			step;
	t_int_point			pos;
	int					color;
	float				perp_wall_distant;
	int					is_hit;
	int					hit_side;
	int					line_s;
	int					line_e;
	int					line_hight;
}	t_raydata;

typedef struct s_data
{
	mlx_t				*mlx;
	mlx_image_t			*img_game;
	mlx_image_t			*img_maps;
	t_parser_data		*parser_data;
	t_texture_assets	*texture;
	t_maps_data			*maps;
	t_player_data		*player;
}	t_data;

#endif