# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pruenrua <pruenrua@student.42bangkok.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 22:39:14 by pruenrua          #+#    #+#              #
#    Updated: 2024/04/11 16:09:21 by pruenrua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = clang

CFLAGS = -Wall -Wextra -Werror -Wunreachable-code

SRC_DIR = ./src/

LIB_DIR = ./lib/
LIB_MLX_DIR = $(LIB_DIR)MLX42/
LIB_FT_DIR = $(LIB_DIR)libft/
LIB_FILE = $(LIB_FT_DIR)libft.a \
		   $(LIB_MLX_DIR)build/libmlx42.a

LIB_LINK = -L$(LIB_FT_DIR) -L$(LIB_MLX_DIR)build
INCLUDE_FLAG = -I$(LIB_FT_DIR) -I$(LIB_MLX_DIR)build
# INCLUDE_FLAG = -Ilibft -Ilibmlx42 // need to clarify this

UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
MLXLINK_FLAG = -ldl -lglfw -pthread -lm
else ifeq ($(UNAME), Darwin)
MLXLINK_FLAG = -framework Cocoa -framework OpenGL -framework IOKit -L/opt/homebrew/opt/glfw/lib -lglfw
else
MLXLINK_FLAG = -lglfw3 -lopengl32 -lgdi32
endif

HEADER_FILE = $(SRC_DIR)cube.h \
			  $(PARSER_DIR)parser.h \
			  $(RENDER_DIR)render.h \
			  $(SRC_DIR)define.h

# PARSER_FILE = 
# PARSER_DIR = $(SRC_DIR)parser/
# PARSER_SRCS = $(addprefix $(PARSER_DIR), $(PARSER_FILE))

# RENDER_FILE = 
# RENDER_DIR = $(SRC_DIR)render/
# RENDER_SRCS = $(addprefix $(RENDER_DIR), $(RENDER_FILE))

SRCS = $(PARSER_SRCS) \
	   $(RENDER_SRCS) \
	   ./src/main.c



OBJS = $(SRCS:.c=.o) 

%.o: %.c $(HEADER_FILE)
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

all : libft libmlx $(NAME)

libft :
	@make -C $(LIB_FT_DIR)

libmlx :
	@cmake $(LIB_MLX_DIR) -B $(LIB_MLX_DIR)build && make -C $(LIB_MLX_DIR)build -j4

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_FILE) $(LIB_LINK) $(MLXLINK_FLAG)

clean :
	rm -f $(OBJS)

fclean : clean
	make -C $(LIB_FT_DIR) fclean
	make -C $(LIB_MLX_DIR)build/ clean
	rm -f $(NAME)

re : fclean all

.PHONY: all clean fclean re libmlx