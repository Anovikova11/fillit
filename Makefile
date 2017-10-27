# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alnoviko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/20 17:16:45 by alnoviko          #+#    #+#              #
#    Updated: 2017/10/20 17:16:47 by alnoviko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

R = ar

CC = gcc

PART1 = ft_read.c

FILES = $(PART1) 

OBJ = $(FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror -c -I fillit.h

all: $(NAME)

$(NAME): 
	gcc $(FLAGS) $(FILES)
	ar crs $(NAME) $(OBJ)

clean: 
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
