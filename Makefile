
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: francisberger <francisberger@student.42    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/29 13:53:54 by fberger           #+#    #+#              #
#    Updated: 2020/06/03 19:14:55 by francisberg      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export VERBOSE := 0

all: List Queue Stack Vector Map

List:
	make -C Containers/List

Queue:
	make -C Containers/Queue

Stack:
	make -C Containers/Stack

Vector:
	make -C Containers/Vector

Map:
	make -C Containers/Map

clean:
	make clean -C Containers/List
	make clean -C Containers/Queue
	make clean -C Containers/Stack
	make clean -C Containers/Vector
	make clean -C Containers/Map

fclean:
	make fclean -C Containers/List
	make fclean -C Containers/Queue
	make fclean -C Containers/Stack
	make fclean -C Containers/Vector
	make fclean -C Containers/Map

re:
	make re -C Containers/List
	make re -C Containers/Queue
	make re -C Containers/Stack
	make re -C Containers/Vector
	make re -C Containers/Map

.PHONY:	all clean fclean re