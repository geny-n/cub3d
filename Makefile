# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/17 14:29:29 by ngeny             #+#    #+#              #
#    Updated: 2025/03/24 20:56:57 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= cub3D
CFLAG		= -Wall -Wextra -Werror -g
CC			= cc

#------INCLUDES------#
INCDIR 	 		= includes
INC	   	 		= ${INCDIR}/cub3d.h
INCLUDES 		= -I./${MINILBX_PATH}

#-------LIBFT-------#
LIBFT    = ./libft/libft.a

#--------MLX--------#
MINILBX_FILE	= mlx-linux/libmlx_Linux.a
MINILBX_PATH	= mlx-linux/
MLXFLAG 		= -L./${MINILBX_PATH} -lmlx -lXext -lX11 -lm

#------SOURCES------#
SRC = src/
MAINSRC = ${SRC}main.c

FILESRC = ${SRC}file/read_file.c ${SRC}file/check_file.c

INITSRC = ${SRC}init/init_data.c ${SRC}init/init_map.c ${SRC}init/init_player.c ${SRC}init/init_texture.c ${SRC}init/init_image.c
		
UTILSSRC = ${SRC}utils/utils_ft.c ${SRC}utils/utils.c ${SRC}utils/utils_map.c ${SRC}utils/free.c ${SRC}utils/check_wall.c

SETTINGSSRC = ${SRC}set/keypress_manage.c ${SRC}set/set_image.c ${SRC}set/ray_cast.c ${SRC}set/camera.c

SOURCES = ${MAINSRC} ${MAPSRC} ${UTILSSRC} ${INITSRC} ${FILESRC} ${SETTINGSSRC}

#------OBJECTS------#

OBJDIR = ./OBJ/
OBJ = ${SOURCES:${SRC}%.c=${OBJDIR}%.o}

#-------COLORS------#
BLACK 	= \033[0;30m
RED 	= \033[0;31m
GREEN 	= \033[0;32m
YELLOW 	= \033[0;33m
BLUE 	= \033[0;34m
PURPLE 	= \033[0;35m
CYAN 	= \033[0;36m
RESET 	= \033[0m

#-------RULES-------#
all: ${LIBFT} ${MINILBX_FILE} ${NAME}

${NAME} : ${OBJ} 
	@${CC} ${CFLAG} ${INCLUDES} ${OBJ} ${LIBFT} ${MLXFLAG} -o ${NAME}

${OBJDIR}%.o : ${SRC}%.c
	mkdir -p ${dir $@}
	${CC} ${FLAGS} -c -o $@ $<

${LIBFT} :
	@make -sC ./libft

${MINILBX_FILE} :
	@make -sC mlx-linux

clean: 
	rm -rf $(OBJDIR)
	make clean -C ./libft

fclean: clean
	rm -rf ${NAME}
	rm -rf  ${LIBFT}

re: fclean all

.PHONY: all clean fclean re
