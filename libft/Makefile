# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngeny <ngeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/13 16:12:28 by gpaupher          #+#    #+#              #
#    Updated: 2024/12/23 17:34:25 by ngeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a 

INC = includes/
SRC_DIR = src/
OBJ_DIR = obj/

IS_DIR =	${SRC_DIR}ft_is/ft_isalpha.c ${SRC_DIR}ft_is/ft_isdigit.c ${SRC_DIR}ft_is/ft_isalnum.c ${SRC_DIR}ft_is/ft_isascii.c ${SRC_DIR}ft_is/ft_isprint.c\

LST_DIR =	${SRC_DIR}ft_lst/ft_lstnew.c ${SRC_DIR}ft_lst/ft_lstadd_front.c ${SRC_DIR}ft_lst/ft_lstsize.c ${SRC_DIR}ft_lst/ft_lstlast.c ${SRC_DIR}ft_lst/ft_lstadd_back.c\
			${SRC_DIR}ft_lst/ft_lstdelone.c ${SRC_DIR}ft_lst/ft_lstclear.c ${SRC_DIR}ft_lst/ft_lstiter.c ${SRC_DIR}ft_lst/ft_lstmap.c

MEM_DIR =	${SRC_DIR}ft_mem/ft_memcmp.c ${SRC_DIR}ft_mem/ft_memset.c ${SRC_DIR}ft_mem/ft_bzero.c\
			${SRC_DIR}ft_mem/ft_memcpy.c ${SRC_DIR}ft_mem/ft_memmove.c ${SRC_DIR}ft_mem/ft_calloc.c ${SRC_DIR}ft_mem/ft_memchr.c 

PUT_DIR =	${SRC_DIR}ft_put/ft_putchar_fd.c ${SRC_DIR}ft_put/ft_putstr_fd.c ${SRC_DIR}ft_put/ft_putendl_fd.c ${SRC_DIR}ft_put/ft_putnbr_fd.c

STR_DIR =	${SRC_DIR}ft_str/ft_substr.c ${SRC_DIR}ft_str/ft_strjoin.c ${SRC_DIR}ft_str/ft_strtrim.c ${SRC_DIR}ft_str/ft_split.c ${SRC_DIR}ft_str/ft_strncmp.c\
			${SRC_DIR}ft_str/ft_strmapi.c ${SRC_DIR}ft_str/ft_striteri.c ${SRC_DIR}ft_str/ft_strlcat.c ${SRC_DIR}ft_str/ft_strlcpy.c ${SRC_DIR}ft_str/ft_strdup.c\
			${SRC_DIR}ft_str/ft_strnstr.c ${SRC_DIR}ft_str/ft_strlen.c ${SRC_DIR}ft_str/ft_strchr.c ${SRC_DIR}ft_str/ft_strrchr.c ${SRC_DIR}ft_str/ft_strcmp.c 

TO_DIR =	${SRC_DIR}ft_to/ft_toupper.c ${SRC_DIR}ft_to/ft_tolower.c ${SRC_DIR}ft_to/ft_atoi.c ${SRC_DIR}ft_to/ft_itoa.c

PRINTF_DIR =	${SRC_DIR}ft_printf/ft_printf_ptr.c ${SRC_DIR}ft_printf/ft_printf_put.c ${SRC_DIR}ft_printf/ft_printf_putnbr.c\
				${SRC_DIR}ft_printf/ft_printf_utoa.c ${SRC_DIR}ft_printf/ft_printf.c

GNL_DIR =		${SRC_DIR}get_next_line/get_next_line.c ${SRC_DIR}get_next_line/get_next_line_utils.c


SRCS = ${IS_DIR} ${LST_DIR} ${MEM_DIR} ${PUT_DIR} ${STR_DIR} ${TO_DIR} ${PRINTF_DIR} ${GNL_DIR} 

OBJ = ${SRCS:.c=.o}

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f
## AR = ar rcs

all : ${NAME}

${NAME} : ${OBJ}
	@${AR} -rcs ${NAME} ${OBJ}
	
${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@${CC} ${CFLAGS} ${INC} -c $< -o $@

clean :
	@${RM} -r ${OBJ}

fclean : clean
	@${RM} ${NAME}

re : fclean all

.PHONY :
	all clean fclean re
