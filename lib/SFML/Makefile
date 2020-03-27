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

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CPPFLAGS	+= -W -Wall -Wextra -Werror -I./include/ -I./../../include/ -I./../../include/entity/ -lsfml-graphics -lsfml-window -lsfml-system -fPIC


all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -shared

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
