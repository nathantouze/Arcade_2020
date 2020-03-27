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

CPPFLAGS	+=	-W -Wall -Wextra -Wextra -I./include/ -I./../../include/ -I./include/entity/ -ldl -lsfml-graphics -lsfml-window -lsfml-system -lncurses -lallegro


all:		$(NAME)

$(NAME):	core
			make -C $(DIRLIB)
			make -C $(DIRGAME)

core:		$(OBJS)
			$(CC) -o $(NAME) $(OBJS) $(CPPFLAGS)

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
