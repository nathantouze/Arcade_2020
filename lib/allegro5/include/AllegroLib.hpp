/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroLib
*/

#ifndef ALLEGROLIB_HPP_
#define ALLEGROLIB_HPP_

#include <allegro5/allegro5.h>
#include "ILibIO.hpp"
#include "TypeEntity.hpp"
#include "Event.hpp"

class AllegroLib : public ILibIO {
    public:
        AllegroLib();
        ~AllegroLib();
        void initWindow();
        void display() const;
        void drawEntity(const IEntity &entity);
        void displayMenu(const MenuInfo &menu);
        Event eventListener() const;
        void clearWindow();
        void destroyWindow();
        bool isOpen() const;

    protected:
    private:
};

extern "C" {
    ILibIO *entryPoint() {
        return (new AllegroLib());
    }
}

#endif /* !ALLEGROLIB_HPP_ */
