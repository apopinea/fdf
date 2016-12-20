# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apopinea <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 11:05:55 by apopinea          #+#    #+#              #
#    Updated: 2016/11/22 15:07:18 by apopinea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean, fclean, re, $(NAME)

.SUFFIXES:

NAME = libft.a
DIR_HEADER = -I./
SRC =	ft_putchar.c \
		ft_putstr.c \
		ft_atoi.c \
		ft_putnbr.c \
		ft_strdup.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_strcmp.c \
		ft_memccpy.c \
		ft_strcpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strncpy.c \
		ft_strcat.c \
		ft_strncat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strstr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_isalpha.c \
		ft_isalnum.c \
		ft_isdigit.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_memalloc.c \
		ft_memdel.c \
		ft_strnew.c \
		ft_strdel.c \
		ft_strclr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strequ.c \
		ft_strnequ.c \
		ft_strsub.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_strsplit.c \
		ft_itoa.c \
		ft_pow.c \
		ft_putendl.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_getstr.c \
		ft_memdup.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lecture_f.c \
		ft_rememalloc.c \
		ft_lstpushback.c \
		ft_lpause.c \
		ft_tabscpy.c \
		ft_strscut.c \
		ft_strswap.c \
		ft_lstdelif_n.c \
		get_next_line.c \
		ft_atoi_base.c \
		ft_putfloat.c \
		ft_cre_matrix.c \
		ft_print_matrix.c \
		ft_opera_matrix.c \
		ft_mult_matrix.c \
		ft_del_matrix.c \
		ft_resize_matrix.c \
		ft_det_matrix.c \
		ft_dup_matrix.c \
		ft_com_matrix.c \
		ft_nb_mult_matrix.c \
		ft_invers_matrix.c \
		ft_div_matrix.c \
		ft_lstprint.c \
		ft_error_r.c \
		ft_success.c
SRO = $(SRC:.c=.o)
FLAG = -Wall -Werror -Wextra
CC = gcc

all: $(NAME)

$(NAME): $(SRO)
	@ar rc $(NAME) $(SRO)
	@ranlib $(NAME)
	@echo "\033[1m\033[32mSuccess : \033[0m compilation libft.a"

$(SRO): $(SRC)
	@$(CC) $(FLAG) -c $(SRC) $(DIR_HEADER)

clean:
	@rm -f $(SRO)
	@echo "\033[1m\033[31msuppression libft *.o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1m\033[31msuppression libft.a\033[0m"

re: fclean all

ree: re
	@rm -f $(SRO)
	@echo "\033[1m\033[31msuppression 2 libft *.o\033[0m"
