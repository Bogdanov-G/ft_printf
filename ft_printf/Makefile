# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Dykk Dessie <gleb_bogdan@mail.ru>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/01 14:35:29 by Dykk Dessie       #+#    #+#              #
#    Updated: 2021/12/11 14:30:50 by Dykk Dessie      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

HEADER	=	ft_printf.h

SRC		=	ft_conv.c ft_litob.c ft_parsflag.c ft_parswidth.c ft_specpars.c\
			ft_strlen.c ft_vprintf.c ft_isdigit.c ft_memcpy.c ft_parsprec.c\
			ft_printf.c ft_specconv.c ft_strchr.c ft_strspec.c

OBJ		=	$(SRC:.c=.o)

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror

RM		=	rm -f

LIB		=	ar rcs

all		:	$(NAME)

$(NAME)	:	$(OBJ)
				$(LIB) $(NAME) $(OBJ)

%.o		:	%.c $(HEADER)
				$(CC) $(CFLAGS) -c -o $@ $<

clean	:
			$(RM) $(OBJ)

fclean	:	clean
				$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all, clean, fclean, re

bonus	: 	all
