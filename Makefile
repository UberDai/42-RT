# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amaurer <amaurer@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/11 01:49:54 by amaurer           #+#    #+#              #
#    Updated: 2015/10/05 19:51:30 by amaurer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC_DIR		=	src/
OBJ_DIR		=	build/
INC_DIR		=	include libft minilibx \
				$(HOME)/libs/ftlst
BIN_DIR		=	bin/

NAME		=	rtv1
BIN_NAME	=	$(BIN_DIR)$(NAME)
SRC_FILES	=	main.c \
				vec3.c \
				util.c \
				render.c \
				ray.c \
				scene.c \
				raycast/raycast.c \
				raycast/hit.c \
				raycast/raycast_sphere.c \
				raycast/raycast_plane.c \
				raycast/raycast_poly.c \
				raycast/raycast_cylinder.c \
				raycast/raycast_cone.c \
				light.c \
				color.c \
				camera.c \
				object.c \
				material.c \
				parser/parser.c \
				parser/parse_scene.c \
				parser/parse_sphere.c \
				parser/parse_vec3.c \
				mlx/color1.c \
				mlx/color2.c \
				mlx/draw_line.c \
				mlx/draw_line_gradient.c \
				mlx/draw_pixel.c \
				mlx/draw_rect.c \
				mlx/hooks.c \
				mlx/mlx.c

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(subst $(SRC_DIR), $(OBJ_DIR), $(SRC:.c=.o))

CC			=	clang
CC_FLAGS	=	-Wall -Werror -Wextra -pedantic -g3
CC_LIBS		=	-lftlst -L$(HOME)/libs/ftlst \
				-lft -Llibft -lmlx -Lminilibx -framework OpenGL -framework AppKit

all: libft minilibx $(BIN_NAME)
	@echo "\033[32m•\033[0m $(NAME) is ready."

$(BIN_NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) -o $(BIN_NAME) $(CC_LIBS) $^

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CC_FLAGS)$(subst $() $(), -I, $(INC_DIR)) -o $@ -c $<

clean:
	make -C libft clean
	rm -rf $(OBJ_DIR)

fclean: clean
	make -C libft fclean
	rm -rf $(BIN_NAME)

re: fclean all

libft:
	@make -C libft

minilibx:
	@make -C minilibx

.PHONY: all re fclean clean libft minilibx