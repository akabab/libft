# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 16:39:11 by ycribier          #+#    #+#              #
#    Updated: 2013/12/31 00:07:03 by ycribier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror
NAME	=	pipex
INCLUDES=	includes/
LIB		=	libft/libft.a
LIB_PATH=	libft/
SRCS	=	pipex.c dbg.c
OBJS	=	$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJS)
	$(CC) -o $@ $^ -L $(LIB_PATH) -lft

$(LIB):
	make -C $(LIB_PATH)

%.o: %.c
	$(CC) -c -o $@ $^ -I $(INCLUDES) -I $(LIB_PATH)$(INCLUDES)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
