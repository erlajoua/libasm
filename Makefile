# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <erlajoua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 10:45:17 by erlajoua          #+#    #+#              #
#    Updated: 2020/11/19 19:03:41 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS =	ft_strlen.s \
		ft_strcpy.s \
		ft_write.s	\
		ft_strdup.s	\
		ft_strcmp.s	\
		ft_read.s

OBJS = $(SRCS:.s=.o)

%.o	: %.s
	nasm -f elf64 $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
