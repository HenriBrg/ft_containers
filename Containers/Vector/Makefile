CC			=	clang++

VERSION		=  # -std=c++98

CPPFLAGS	=	-Wall -Werror -Wextra -g

RM			=	rm -rf

SRCS		=	main.cpp
OBJS		= 	$(SRCS:.cpp=.o)
EXEC		=	a.out

ifeq ($(VERBOSE),)
	export VERBOSE := 1
endif

all:
	${CC} ${VERSION} ${CPPFLAGS} -o $(EXEC) $(SRCS)
	./$(EXEC)

clean:
	$(RM) $(OBJS)
	$(RM) ./a.out.dSYM

fclean: clean
	$(RM) $(EXEC)

re:	fclean all

.PHONY:	all clean fclean re
