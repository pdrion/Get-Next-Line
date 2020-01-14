#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 14:19:39 by pdrion            #+#    #+#              #
#    Updated: 2020/01/14 17:57:38 by pdrion           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= gnl.a

SRCS		= get_next_line.c \
			  get_next_line_utils.c \

OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)
f:			all
			gcc gnl.a main.c -D BUFFER_SIZE=11

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all
