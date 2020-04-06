##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	lib_arcade_centipede.so

DIR		=	./src

SRCS	=	$(DIR)/Centipede.cpp			\
			$(DIR)/Entity.cpp				\
			$(DIR)/Gnome.cpp				\
			$(DIR)/MushroomManager.cpp		\
			$(DIR)/ScoreManager.cpp			\
			$(DIR)/Mushroom.cpp				\
			$(DIR)/ShootManager.cpp			\
			$(DIR)/insects/Centi.cpp		\
			$(DIR)/insects/CentiManager.cpp	\
			$(DIR)/insects/InsectsManager.cpp		\
			$(DIR)/insects/Slug.cpp			\
			$(DIR)/insects/Smurf.cpp		\
			$(DIR)/insects/Spider.cpp		\
			

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
