##
## EPITECH PROJECT, 2020
## arcade
## File description:
## Makefile
##

NAME	=	lib_arcade_libname.so

DIR		=	./src

SRCS	=	$(DIR)/MenuInfo.cpp			\
			$(DIR)/Entity.cpp			\

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CPPFLAGS	+= -W -Wall -Wextra -Werror -I./include/ -fPIC -std=c++17

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -shared -rdynamic

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
