/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroPicture
*/

#ifndef ALLEGROPICTURE_HPP_
#define ALLEGROPICTURE_HPP_

#include "AllegroManager.hpp"
#include <allegro5/allegro_image.h>
#include <map>

namespace AllegroManager {
class AllegroPicture {
    public:
        AllegroPicture();
        void loadPicture(const std::string &path);
        void displayPicture(const std::string &path, int posX, int posY);
        ~AllegroPicture();

    protected:
    private:
        std::map<std::string, ALLEGRO_BITMAP *> _bitmapList;
};
}

#endif /* !ALLEGROPICTURE_HPP_ */
