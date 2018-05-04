# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ardurand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/30 17:12:23 by ardurand          #+#    #+#              #
#    Updated: 2017/10/31 15:55:23 by ardurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_DIR = srcs/
SRC = 	lem_in.c ft_process_read.c ft_process_phase_1.c ft_check_phase_2.c \
		ft_process_phase_2.c ft_find_path.c ft_check_end.c ft_sup_path.c \
		ft_remove_non_end_path.c ft_set_len_path.c ft_set_ant_path.c \
		ft_print_ant.c ft_isint.c ft_freetab.c ft_freedim2.c

OBJ_DIR = objs/
OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

INC = -Ilib/incs -Iincs

LIB_DIR = lib/
LIB_LNK = -L$(LIB_DIR) -lftprintf -lft -llst
LIB = $(addprefix $(LIB_DIR), libft.a libftprintf.a liblst.a)

CC = gcc
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIB) $(OBJ_DIR) $(OBJ)
	@$(CC) $(CFLAGS) $(LIB_LNK) $(OBJ) -o $(NAME)

$(LIB):
	@make -C lib

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make -C lib clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@make -C lib fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
