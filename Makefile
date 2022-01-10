# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 15:44:04 by bterral           #+#    #+#              #
#    Updated: 2022/01/10 15:40:36 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/////////////////////////#
#   FILES AND FOLDERS     #
#/////////////////////////#

NAME = so_long

SRCS_FILES = so_long.c map_parsing.c map_parsing_utils.c game.c map_parsing_walls.c

SRCS_FOLDER = ./srcs/

SRCS = $(addprefix ${SRCS_FOLDER},${SRCS_FILES})

OBJS = ${SRCS:.c=.o}

INCLUDES_FOLDER = ./includes/

INCLUDES_FILES = so_long.h keys.h mlx.h

INCLUDES = $(addprefix ${INCLUDES_FOLDER},${INCLUDES_FILES})

LIB_GNL = ./get_next_line/lib_get_next_line.a

LIB_MLX = ./minilibx/libmlx.a

#/////////////////////////#
#        COMPILATION      #
#/////////////////////////#

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

FRAMEWORK = -framework OpenGL -framework AppKit

#/////////////////////////#
#         RULES           #
#/////////////////////////#

all: ${NAME}

${NAME}: ${INCLUDES} ${SRCS} ${LIB_GNL} ${LIB_MLX}
	${CC} -o ${NAME} -I ${INCLUDES_FOLDER} ${CFLAGS} ${SRCS} ${LIB_GNL} ${LIB_MLX} ${FRAMEWORK}

${LIB_GNL}:
	$(MAKE) -C ./get_next_line

${LIB_MLX}:
	$(MAKE) -C ./minilibx

clean:
	${RM} ${OBJS}
	$(MAKE) clean -C ./get_next_line
	$(MAKE) clean -C ./minilibx

fclean: clean
	${RM} ${NAME}
	$(MAKE) fclean -C ./get_next_line

re: fclean all

.PHONY: all bonus clean fclean re