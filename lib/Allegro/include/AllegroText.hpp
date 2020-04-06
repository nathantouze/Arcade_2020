/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroText
*/

#ifndef ALLEGROTEXT_HPP_
#define ALLEGROTEXT_HPP_

#include "AllegroManager.hpp"
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include "map"

namespace AllegroManager {
class AllegroText {
    public:
        AllegroText();
        void initText();
        void loadFont(const std::string &path, int size);
        void drawText(const std::string &font, int size, const std::string &text, ALLEGRO_COLOR color, int x, int y);
        void destroyAllFont();
        ~AllegroText();

    protected:
    private:
        std::map<std::pair<std::string, int>, ALLEGRO_FONT*> _fontList;
};
}

#endif /* !ALLEGROTEXT_HPP_ */
