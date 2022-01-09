# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/09 15:44:04 by bterral           #+#    #+#              #
#    Updated: 2022/01/09 15:51:19 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/////////////////////////#
#   FILES AND FOLDERS    /#
#/////////////////////////#

NAME = so_long

SRCS_FILES = so_long.c map_parsing.c map_parsing_utils.c game.c

SRCS_FOLDER = ./srcs/

SRCS = $(addprefix ${SRCS_FOLDER},${SRCS_FILES})

OBJS = ${SRCS:.c=.o}

SRCS_GET_NEXT_LINE = 

SRCS_FOLDER_GET_NEXT_LINE = ./get_next_line/

#/////////////////////////#
#        COMPILATION     /#
#/////////////////////////#

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f