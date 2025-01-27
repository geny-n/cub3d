# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/16 15:21:03 by ngeny             #+#    #+#              #
#    Updated: 2025/01/27 14:40:30 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

GREEN = \033[0;32m
WHITE=\033[0m

LIBFT    = ./libft/libft.a
OBJDIR = ./OBJ/

CC = cc
FLAGS = -Wall -Wextra -Werror -g

MLX_PATH = minilibx-linux/
MLX = minilibx-linux/libmlx_Linux.a
MLXFLAG = -lXext -lX11
MINILIBX = ${MLX} ${MLXFLAG}
INC_MLX = minilibx-linux/
INCLUDES = -I./${INC_MLX}

#############################################################################
SRC = src/
MAINSRC =	${SRC}main.c \

REDIRECTIONSSRC =	${SRC}redirections/redirection.c \
					${SRC}redirections/here_doc.c \
					
BUILTINSSRC =	${SRC}builtins/ft_echo.c \
				${SRC}builtins/ft_env.c \
				${SRC}builtins/ft_cd.c \
				${SRC}builtins/ft_cd_utils.c \
				${SRC}builtins/ft_pwd.c \
				${SRC}builtins/ft_export.c \
				${SRC}builtins/ft_export_utils.c \
				${SRC}builtins/ft_unset.c \
				${SRC}builtins/ft_exit.c \

UTILSSRC =	${SRC}utils/init_list.c \
			${SRC}utils/utils.c \
			${SRC}utils/utils_builtins.c \
			${SRC}utils/signals.c \
			${SRC}utils/signal_fork.c \
			${SRC}utils/prompt.c \
			${SRC}utils/free.c \
			${SRC}utils/free2.c \
			${SRC}utils/error_message.c \

PARSINGSRC =	${SRC}parsing/parsing.c \
				${SRC}parsing/parsing_type.c \
				${SRC}parsing/parsing_sep.c \
				${SRC}parsing/parsing_expansion.c \
				${SRC}parsing/parsing_dollar.c \
				${SRC}parsing/parsing_list.c \
				${SRC}parsing/parsing_count.c \
				${SRC}parsing/parsing_tkn.c \
				${SRC}parsing/parsing_utils.c \

EXECUTESRC =	${SRC}execute/close_all.c \
				${SRC}execute/exe_one_proc.c \
				${SRC}execute/exec_proc_bis.c \
				${SRC}execute/exec.c \
				${SRC}execute/exec_utils.c \
				${SRC}execute/exec_utils2.c \
				${SRC}execute/exec_list.c \
				${SRC}execute/exec_built.c \
				${SRC}execute/exec_proc.c \

SOURCES = ${MAINSRC} ${REDIRECTIONSSRC} ${BUILTINSSRC} ${UTILSSRC} ${PARSINGSRC} ${EXECUTESRC}

#############################################################################
OBJ = ${SOURCES:${SRC}%.c=${OBJDIR}%.o}

#############################################################################
all: ${LIBFT} ${MLX} ${NAME}

${LIBFT} :
	@make -sC ./libft
${MLX} :
	@make -sC ./minilibx-linux

${NAME} : ${OBJ} ${LIBFT} ${MINILIBX}
	${CC} ${FLAGS} ${OBJ} ${LIBFT}  ${MINILIBX} -o ${NAME}
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