##
## EPITECH PROJECT, 2020
## cpp_rush3_2019
## File description:
## Makefile
##

NAME	=	lib_arcade_allegro5.so

DIR		=	./src

SRCS	=	$(DIR)/AllegroLib.cpp	\
			$(DIR)/MenuInfo.cpp		\
			$(DIR)/Entity.cpp		\

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CPPFLAGS	+= -W -Wall -Wextra -Werror -I./include/ -I./../../include/ -I./../../include/entity/ -lallegro -fPIC

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -shared

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
