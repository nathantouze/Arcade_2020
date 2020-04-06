##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

NAME	=	arcade

DIRCORE	=	./src

DIRLIB	=	./lib

DIRGAME	=	./games

SRCS	=	$(DIRCORE)/main.cpp					\
			$(DIRCORE)/DLLoaderException.cpp	\
			$(DIRCORE)/Entity.cpp				\
			$(DIRCORE)/Core.cpp					\
			$(DIRCORE)/MenuInfo.cpp				\
			$(DIRCORE)/MenuArcade.cpp			\
			$(DIRCORE)/DirectoryReader.cpp		\
			$(DIRCORE)/TimerFPS.cpp				\
			$(DIRCORE)/ScoreModule.cpp			\
			$(DIRCORE)/FileManager.cpp			\

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CXXFLAGS	+=	-W -Wall -Wextra -Wextra -I./include/ -I./../../include/ -I./include/entity/ -std=c++17 -g


all:		$(NAME)

$(NAME):	core
			make -C $(DIRLIB)
			make -C $(DIRGAME)

core:		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -ldl


graphicals:
			make -C $(DIRLIB)

games:
			make -C $(DIRGAME)

clean:
			$(RM) $(OBJS)
			make clean -C $(DIRLIB)
			make clean -C $(DIRGAME)

fclean:		clean
			rm -rf $(NAME)
			make fclean -C $(DIRLIB)
			make fclean -C $(DIRGAME)

re:			fclean all

.PHONY:		all core games graphicals clean fclean
