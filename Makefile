# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dirony <dirony@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/05 20:08:26 by dirony            #+#    #+#              #
#    Updated: 2021/11/24 22:16:14 by dirony           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

HEADER_B = ft_printf_bonus.h

SRC = 		ft_printf.c				number_utils.c\
			string_utils.c			print_utils.c\
			putnbr_utils.c			flag_utils.c\
			print_string_utils.c

SRC_BONUS = ft_printf_bonus.c		number_utils_bonus.c\
			string_utils_bonus.c	print_utils_bonus.c\
			putnbr_utils_bonus.c	flag_utils_bonus.c\
			print_string_utils_bonus.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

CFLAGS = -Wall -Werror -Wextra

COMPILE = gcc $(CFLAGS) -c

LIB = ar rc $(NAME)

REMOVE = rm -f

%.o 	:	%.c	$(HEADER)
			$(COMPILE) $< -o $@


.PHONY: all bonus clean fclean re

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@$(COMPILE) $(SRC)
	@$(LIB) $(OBJ)

bonus:
	@make OBJ="$(OBJ_BONUS)" HEADER="$(HEADER_B)" all

clean:
	@$(REMOVE) $(OBJ) $(OBJ_BONUS)

fclean: clean
	@$(REMOVE) $(NAME)

re: fclean all
