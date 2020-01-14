#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdrion <pdrion@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 14:19:39 by pdrion            #+#    #+#              #
#    Updated: 2019/12/20 18:27:39 by pdrion           ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		= gnl.a

SRCS		= get_next_line.c \
			  get_next_line_utils.c \
			  main.c\

OBJS		= $(SRCS:.c=.o)

CC			= gcc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -D BUFFER_SIZE=32

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re: fclean all
