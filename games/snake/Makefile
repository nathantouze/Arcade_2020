##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	lib_arcade_nibbler.so

DIR		=	./src

SRCS	=	$(DIR)/Snake.cpp			\
			$(DIR)/Entity.cpp			\

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CPPFLAGS	+= -W -Wall -Wextra -Werror -I./include/ -I./../../include/ -I./../../include/entity/ -fPIC -std=c++17


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -shared -rdynamic

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
