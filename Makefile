# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpaupher <gpaupher@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:21:03 by ngeny             #+#    #+#              #
#    Updated: 2025/01/27 18:30:02 by gpaupher         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
FLAGS = -Wall -Wextra -Werror -g


#-------LIBFT-------#

LIBFT    = ./libft/libft.a

#--------MLX--------#

MLX_PATH = minilibx-linux/
MLX = minilibx-linux/libmlx_Linux.a
MLXFLAG = -lX11 -lXext
MINILIBX = ${MLX} ${MLXFLAG}

#------INCLUDES------#

INC_LIBFT = libft/includes/
INC_CUB = includes/
INC_MLX = minilibx-linux/
INCLUDES = -I./${INC_CUB} -I./${INC_LIBFT} -I./${INC_MLX}

#------SOURCES------#

SRC = src/
MAINSRC = ${SRC}main.c
SOURCES = ${MAINSRC}

#-------BONUS-------#

#------OBJECTS------#

OBJDIR = ./OBJ/
OBJ = ${SOURCES:${SRC}%.c=${OBJDIR}%.o}

#-------COLORS------#

GREEN = \033[0;32m
WHITE=\033[0m
#-------RULES-------#

all: ${LIBFT} ${MLX} ${NAME}

${LIBFT} :
	@make -sC ./libft
${MLX} :
	@make -sC ./minilibx-linux

${NAME} : ${OBJ}
	${CC} ${FLAGS} ${INCLUDES} ${OBJ} ${LIBFT}  ${MINILIBX} -o ${NAME}
	@echo "${GREEN}*************  Compilation success  *************${WHITE}"

${OBJDIR}%.o : ${SRC}%.c
	mkdir -p ${dir $@}
	${CC} ${FLAGS} -c -o $@ $<
	
#############################################################################
clean :
	rm -rf $(OBJDIR)
	make clean -C ./libft
	make clean -C ${MLX_PATH}

fclean : clean
	rm -rf ${NAME}
	rm -rf  ${LIBFT}

re : fclean all

.PHONY :
	all clean fclean re