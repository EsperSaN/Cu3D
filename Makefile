# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 22:39:14 by pruenrua          #+#    #+#              #
#    Updated: 2024/06/12 23:52:54 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code

SRC_DIR = src
INC_DIR = ./include/
BUILD_DIR = build

# lib source

LIB_DIR = ./lib
LIB_MLX_DIR = $(LIB_DIR)/MLX42
LIB_FT_DIR = $(LIB_DIR)/libft
LIB_FILE = $(LIB_FT_DIR)/libft.a \
		   $(LIB_MLX_DIR)/build/libmlx42.a

#--library-directory
LIB_LINK = -L$(LIB_FT_DIR) -L$(LIB_MLX_DIR)build
INCLUDE_FLAG = -I$(LIB_FT_DIR)/ \
			   -I$(LIB_FT_DIR)/get_next_line/\
			   -I$(LIB_MLX_DIR)/build/ \
			   -I$(LIB_MLX_DIR)/include/MLX42/ \
			   -Iinclude/

#header source
HEADER_FILE = cube.h\
		 	define.h\
		 	free.h\
		 	parser.h\
		 	render.h\
		 	util.h
HEADER_SRC = $(addprefix $(INC_DIR), $(HEADER_FILE))

#render source
RENDER_FILE = clear_image.c\
			  do_dda.c\
			  draw_line_with_texture.c\
			  find_range_to_draw.c\
			  init_ray.c\
			  draw_map.c\
			  draw_squre.c\
			  draw_line.c\
			  prepare_render.c\
			  key_hook.c\
			  floor_cast.c\
			  ceil_cast.c\
			  ray_casting.c\
			  main_render.c
RENDER_DIR = $(SRC_DIR)/render/
RENDER_SRCS = $(addprefix $(RENDER_DIR), $(RENDER_FILE))

#util source
UTIL_FILE = puterror.c \
		    putreport.c \
			is_same_str.c \
			is_right_extension.c \
			is_file_valid.c \
			is_file_readable.c \
			get_rgba.c \
			get_rad.c \
			get_png_texture.c \
			ft_cos.c \
			ft_sin.c \
			rotate_vector.c
UTIL_DIR = $(SRC_DIR)/util/
UTIL_SRCS = $(addprefix $(UTIL_DIR), $(UTIL_FILE))

#parser source
PARSER_FILE = \
		get_element_check.c\
		ft_split_no_cut.c\
		border_checker.c \
		check_resource.c \
		count_value_line.c \
		file_reader.c \
		find_first_of.c \
		find_height_width.c \
		find_last_of.c \
		free_2dwithres.c \
		ft_floodfill.c \
		ft_isprint_mk2.c \
		ft_isspace.c \
		get_ceil_floor.c \
		get_texture_file.c \
		init_map.c \
		is_map_element.c \
		is_map_line.c \
		is_numline.c \
		main_parser.c \
		read_loop.c \
		scan4player.c \
		set_from_parser_data.c \
		set_maps_data.c \
		set_texture_assets.c \
		src_checker.c 
PARSER_DIR = $(SRC_DIR)/parser/
PARSER_SRCS = $(addprefix $(PARSER_DIR), $(PARSER_FILE))

# free source
FREE_FILE = free_maps_data.c\
			free_parser_data.c\
			free_player_data.c\
			free_texture_assets.c\
			free_texture.c\
			term_and_cleanup.c\
			free_two_d.c

FREE_DIR = $(SRC_DIR)/free/
FREE_SRCS = $(addprefix $(FREE_DIR), $(FREE_FILE))


# for dev in muti platform
UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
MLXLINK_FLAG = -ldl -lglfw -pthread -lm
else ifeq ($(UNAME), Darwin)
MLXLINK_FLAG = -framework Cocoa -framework OpenGL -framework IOKit -L/opt/homebrew/opt/glfw/lib -lglfw
else
MLXLINK_FLAG = -lglfw3 -lopengl32 -lgdi32
endif

# all source before compile
SRCS = $(UTIL_SRCS) \
	   $(FREE_SRCS) \
	   $(PARSER_SRCS) \
	   $(RENDER_SRCS) \
	   ./src/main.c

# rule
all : $(NAME)

OBJS = $(SRCS:%.c=$(BUILD_DIR)/%.o)

$(OBJS): $(BUILD_DIR)/%.o: %.c $(HEADER_SRC)
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

$(NAME) : libmlx libft $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_FILE) $(LIB_LINK) $(MLXLINK_FLAG)

clean :
	make -C $(LIB_FT_DIR) clean
	$(RM) -r $(BUILD_DIR)

fclean : clean
	make -C $(LIB_FT_DIR) fclean
	make -C $(LIB_MLX_DIR)/build/ clean
	$(RM) -r $(BUILD_DIR)
	rm -f $(NAME)

libmlx :
	cmake $(LIB_MLX_DIR) -B $(LIB_MLX_DIR)/build && make -C $(LIB_MLX_DIR)/build -j4

libft :
	make -C $(LIB_FT_DIR)

norm : 
	norminette $(LIB_FT_DIR) $(HEADER_SRC) $(SRCS)

val : $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes -s ./$(NAME) maps/valid/subject.cub

re : fclean all

.PHONY: all clean fclean norm re libmlx libft