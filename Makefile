# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybargach <ybargach@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/03 22:22:59 by ybargach          #+#    #+#              #
#    Updated: 2023/06/04 16:55:13 by ybargach         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRC = error.c function.c \
		pipex.c function_utils.c function_utils_2.c check.c fd_fail.c \

BONUS = bonus/error_bonus.c bonus/function_bonus.c bonus/get_next_line_utils.c bonus/get_next_line.c bonus/here_doc_bonus.c \
		bonus/pipex_bonus.c bonus/function_utils_bonus.c bonus/function_utils_2_bonus.c bonus/check_bonus.c bonus/fd_fail_bonus.c \

NAME = pipex
NAMEB = pipex_bonus

OBJ = $(SRC:.c=.o)
OBJS = $(BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

bonus : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAMEB)

clean:
	rm -f $(OBJ) $(OBJS)

fclean:
	rm -f $(OBJ) $(NAME) $(OBJS) $(NAMEB)

re: fclean all