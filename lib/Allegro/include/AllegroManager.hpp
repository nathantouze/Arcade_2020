/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroManager
*/

#ifndef ALLEGROMANAGER_HPP_
#define ALLEGROMANAGER_HPP_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include "AllegroException.hpp"

namespace AllegroManager {
class AllegroManager {
    public:
        AllegroManager();
        void initAllegro() const;
        void display() const;
        void createWindow(const int width, const int height);
        void clearWindow(int r, int g, int b);
        void destroyWindow();
        bool isWindowOpen() const;
        ALLEGRO_DISPLAY *getWindow();
        ~AllegroManager();

    protected:
    private:
        bool _isWindowOpen;
        ALLEGRO_DISPLAY *_window;
};
}

#endif /* !ALLEGROMANAGER_HPP_ */
