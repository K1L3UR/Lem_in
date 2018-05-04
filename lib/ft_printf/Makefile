# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ardurand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 16:23:23 by ardurand          #+#    #+#              #
#    Updated: 2017/10/31 16:23:41 by ardurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC_DIR = srcs/
SRC =	ft_backslash.c ft_bintoint.c ft_flags.c ft_llbtoa.c ft_lltoa.c \
		ft_padpos.c ft_printf.c ft_type.c ft_typec.c ft_typed.c \
		ft_typenumeric.c ft_typeo.c ft_types.c ft_typestr.c ft_typeu.c \
		ft_typewc.c ft_typews.c ft_typex.c ft_dprintf.c ft_sqrt.c

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = -I../incs

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@ar -rc $(NAME) $(OBJ)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
