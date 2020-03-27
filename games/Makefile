##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SNAKENAME	=	lib_arcade_nibbler.so

SNAKEDIR	=	./snake

CENTINAME	=	lib_arcade_centipede.so

CENTIDIR	=	./centipede

RM			=	rm -rf

all:
			make -C $(SNAKEDIR)
			cp $(SNAKEDIR)/$(SNAKENAME) ./
			make -C $(CENTIDIR)
			cp $(CENTIDIR)/$(CENTINAME) ./

clean:
			make clean -C $(SNAKEDIR)
			make clean -C $(CENTIDIR)

fclean:
			make fclean -C $(SNAKEDIR)
			$(RM) $(SNAKENAME)
			make fclean -C $(CENTIDIR)
			$(RM) $(CENTINAME)

re:			fclean all

.PHONY:		all clean fclean re