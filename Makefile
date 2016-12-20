# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apopinea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:05:55 by apopinea          #+#    #+#              #
#    Updated: 2016/11/17 10:09:57 by jyakdi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, $(LIBFT_A), $(NAME_PROG)

.SUFFIXES:

NAME = fdf
LIBFT_A = ./libft/libft.a
DIR_LIBFT = ./libft/
DIR_H_LIBFT = ./libft
DIR_M = ./srcs/
DIR_H = ./includes
SRCM =	main.c 				\
		ft_trace_map.c 		\
		ft_trace_map_2.c 	\
		ft_trace_map_3.c 	\
		ft_trace_map_4.c 	\
		ft_trace_map_5.c 	\
		get_map.c 			\
		convert_map.c 		\
		convert_map_2.c 	\
		get_file_param.c 	\
		init_param.c 		\
		init_param_2.c 		\
		init_param_3.c 		\
		init_param_4.c 		\
		init_param_5.c 		\
		block_prepa_map.c 	\
		block_prepa_map_2.c \
		draw_map.c 			\
		draw_map_2.c 		\
		draw_map_3.c 		\
		hook_fdf.c 			\
		hook_fdf_2.c		\
		menu_touche.c 		\
		menu_touche_2.c 	\
		menu.c 				\
		menu_2.c 			\
		menu_3.c 			\
		menu_4.c 			\
		menu_5.c 			\
		menu_6.c 			\
		menu_7.c 			\
		menu_8.c 			\
		menu_9.c 			\
		exit_fdf.c 			\
		exit_fdf_2.c		\
		outil_debug.c
SROM = $(SRCM:.c=.o)
FULL_PATH = $(addprefix $(DIR_M),$(SRCM))
OPT = -I
FLAG = -Wall -Werror -Wextra
FLAG2 = -lmlx -framework OpenGL -framework AppKit
CC = cc

all: $(NAME)

$(NAME): $(SROM) $(LIBFT_A)
	@$(CC) $(FLAG) -o $@ $^ $(FLAG2)
	@echo "\033[1m\033[32mSuccess : \033[0m compilation fdf"

$(SROM): $(FULL_PATH)
	@$(CC) $(FLAG) -c $^ $(OPT)$(DIR_H_LIBFT) $(OPT)$(DIR_H)

$(LIBFT_A):
	@make -C $(DIR_LIBFT)

clean:
	@rm -f $(SROM)
	@echo "\033[1m\033[31msuppression fdf *.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@cd $(DIR_LIBFT) && $(MAKE) $@
	@echo "\033[1m\033[31msuppression fdf\033[0m"

re: fclean all
