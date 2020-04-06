##
## EPITECH PROJECT, 2020
## cpp_rush3_2019
## File description:
## Makefile
##

NAME	=	lib_arcade_allegro.so

DIR		=	./src

SRCS	=	$(DIR)/AllegroLib.cpp		\
			$(DIR)/FolderDisplay.cpp	\
			$(DIR)/MenuInfo.cpp			\
			$(DIR)/Entity.cpp			\
			$(DIR)/AllegroManager.cpp	\
			$(DIR)/AllegroEvent.cpp		\
			$(DIR)/AllegroException.cpp	\
			$(DIR)/AllegroText.cpp		\
			$(DIR)/AllegroPicture.cpp	\

OBJS	=	$(SRCS:.cpp=.o)

CC		=	g++

RM		=	rm -rf

CPPFLAGS	+= -W -Wall -Wextra -Werror -I./include/ -I./../../include/ -I./../../include/entity/ -fPIC -std=c++17

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) -o $(NAME) $(OBJS) -shared -rdynamic -lallegro -lallegro_primitives -lallegro_font -lallegro_ttf -lallegro_image

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all
