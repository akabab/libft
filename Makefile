# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycribier <ycribier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 16:39:11 by ycribier          #+#    #+#              #
#    Updated: 2015/02/25 14:41:19 by ycribier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc -O2 $(FLAGS)
FLAGS	=	-Wall -Wextra -Werror
NAME	=	libft.a
INCLUDES=	./includes
SRCS	=	ft_memset.c					\
			ft_bzero.c					\
			ft_memcpy.c					\
			ft_memccpy.c				\
			ft_memmove.c				\
			ft_memchr.c					\
			ft_memcmp.c					\
			ft_strlen.c					\
			ft_strdup.c					\
			ft_strcpy.c					\
			ft_strncpy.c				\
			ft_strcat.c					\
			ft_strncat.c				\
			ft_strlcat.c				\
			ft_strchr.c					\
			ft_strrchr.c				\
			ft_strstr.c					\
			ft_strnstr.c				\
			ft_strcmp.c					\
			ft_strncmp.c				\
			ft_atoi.c					\
			ft_isalpha.c				\
			ft_isdigit.c				\
			ft_isalnum.c				\
			ft_isascii.c				\
			ft_isprint.c				\
			ft_toupper.c				\
			ft_tolower.c				\
			ft_str_isdigit.c			\
			ft_str_isint.c				\
			ft_memalloc.c				\
			ft_memdel.c					\
			ft_strnew.c					\
			ft_strdel.c					\
			ft_strclr.c					\
			ft_striter.c				\
			ft_striteri.c				\
			ft_strmap.c					\
			ft_strmapi.c				\
			ft_strequ.c					\
			ft_strnequ.c				\
			ft_strsub.c					\
			ft_strjoin.c				\
			ft_strtrim.c				\
			ft_strsplit.c				\
			ft_strreplace.c				\
			ft_itoa.c					\
			ft_putchar.c				\
			ft_putchar_fd.c				\
			ft_putstr.c					\
			ft_putstr_fd.c				\
			ft_putendl.c				\
			ft_putendl_fd.c				\
			ft_putnbr.c					\
			ft_putnbr_fd.c				\
			ft_lstnew.c					\
			ft_lstdelone.c				\
			ft_lstdel.c					\
			ft_lstadd.c					\
			ft_lstiter.c				\
			ft_lstmap.c					\
			ft_lstpush.c				\
			ft_min.c					\
			ft_abs.c					\
			ft_power.c					\
			degree_radian.c				\
			ft_nbrlen.c					\
			ft_perror.c					\
			free.c						\
			dlist.c						\
			dlist_node.c				\
			dlist_node_rm.c				\
			list.c						\
			list_rm.c					\
			htable.c					\
			htable_rm.c					\
			hft.c						\
			ft_printf.c					\
			dec_oct.c					\
			get_next_line.c
OBJS	=	$(SRCS:.c=.o)

# COLORS
C_NO	=	"\033[00m"
C_OK	=	"\033[35m"
C_GOOD	=	"\033[32m"
C_ERROR	=	"\033[31m"
C_WARN	=	"\033[33m"

# DBG MESSAGE
SUCCESS	=	$(C_GOOD)SUCCESS$(C_NO)
OK		=	$(C_OK)OK$(C_NO)

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "Compiling & indexing" [ $(NAME) ] $(SUCCESS)

%.o: %.c $(INCLUDES)/libft.h
	@$(CC) -c -o $@ $< -I $(INCLUDES)
	@echo "Linking" [ $< ] $(OK)

clean:
	@rm -f $(OBJS)
	@echo "Cleaning" [ $(NAME) ] "..." $(OK)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
