# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bterral <bterral@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/10 09:21:14 by bterral           #+#    #+#              #
#    Updated: 2022/02/23 15:49:17 by bterral          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#/////////////////////////#
#   FILES AND FOLDERS     #
#/////////////////////////#

NAME 			:= lib_get_next_line.a

SRCS_FILES		:= get_next_line.c get_next_line_utils.c libft_utils.c

OBJS_LST		:= $(SRCS_FILES:.c=.o)

SRCS_DIR		:= ./srcs/

OBJS_DIR 		:= ./.objs/

SRCS			:= $(addprefix $(SRCS_DIR),$(SRCS_FILES))

OBJS			:= $(addprefix $(OBJS_DIR), $(OBJS_LST))

INCLUDES_DIR	:= ./includes/

INCLUDES_FILES	:= get_next_line.h

INCLUDES		:= $(addprefix $(INCLUDES_DIR),$(INCLUDES_FILES))

#/////////////////////////#
#        COMPILATION      #
#/////////////////////////#

CC				:= gcc

CFLAGS			:= -Wall -Wextra -Werror

AR				:= ar rcs

RM				:= rm -f

#/////////////////////////#
#         RULES           #
#/////////////////////////#

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c $(INCLUDES) | $(OBJS_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDES_DIR) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all