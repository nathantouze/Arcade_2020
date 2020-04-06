##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	lib_arcade_sfml.so

DIR		=	./src

SRCS	=	$(DIR)/LibSfml.cpp			\
			$(DIR)/MenuInfo.cpp			\
			$(DIR)/Entity.cpp			\
			$(DIR)/Music.cpp			\

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CPPFLAGS	+= -W -Wall -Wextra -Werror -I./include/ -I./../../include/ -I./../../include/entity/ -fPIC -std=c++17


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -shared -rdynamic -lsfml-graphics -lsfml-window -lsfml-system

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
