# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ardurand <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/31 15:55:57 by ardurand          #+#    #+#              #
#    Updated: 2017/10/31 15:56:18 by ardurand         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libftprintf libft liblst

all: $(LIB)

libftprintf:
	@make -C ft_printf
	@cp ft_printf/libftprintf.a .

libft:
	@make -C libft
	@cp libft/libft.a .

liblst:
	@make -C liblst
	@cp liblst/liblst.a .

clean:
	@make -C ft_printf clean
	@make -C libft clean
	@make -C liblst clean

fclean: clean
	@make -C ft_printf fclean
	@make -C libft fclean
	@make -C liblst fclean
	@rm -f $(LIB:=.a)

re: fclean all

.PHONY: all libftprintf libft liblst clean fclean re
