##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SFMLNAME	=	lib_arcade_sfml.so

NCURSENAME	=	lib_arcade_ncurse.so

ALLEGRONAME	=	lib_arcade_allegro.so

SFMLDIR		=	./SFML

NCURSEDIR	=	./Ncurse

ALLEGRODIR	=	./Allegro

RM			=	rm -rf

all:
				make -C $(SFMLDIR)
				cp $(SFMLDIR)/$(SFMLNAME) ./
				make -C $(NCURSEDIR)
				cp $(NCURSEDIR)/$(NCURSENAME) ./
				make -C $(ALLEGRODIR)
				cp $(ALLEGRODIR)/$(ALLEGRONAME) ./

clean:
				make clean -C $(SFMLDIR)
				make clean -C $(NCURSEDIR)
				make clean -C $(ALLEGRODIR)
				

fclean:
				make fclean -C $(SFMLDIR)
				$(RM) $(SFMLNAME)
				make fclean -C $(NCURSEDIR)
				$(RM) $(NCURSENAME)
				make fclean -C $(ALLEGRODIR)
				$(RM) $(ALLEGRONAME)

re:				fclean all

.PHONY: all clean fclean re