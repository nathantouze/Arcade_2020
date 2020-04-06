/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroText
*/

#include "AllegroText.hpp"

namespace AllegroManager {
AllegroText::AllegroText()
{
}

void AllegroText::initText()
{
    al_init_font_addon();
    al_init_ttf_addon();
}

void AllegroText::loadFont(const std::string &path, int size)
{
    std::pair<std::string, int> pairCreate = {path, size};
    if (_fontList.find(pairCreate) == _fontList.end()) {
        _fontList[pairCreate] = al_load_ttf_font(path.c_str(), size, 0);
        if (_fontList[pairCreate] == NULL)
            throw AllegroException("Error during opening font : " + path, "AllegroText");
    }
}

void AllegroText::drawText(const std::string &font, int size, const std::string &text, ALLEGRO_COLOR color, int x, int y)
{
    std::pair<std::string, int> pairCreate = {font, size};

    if (_fontList.find(pairCreate) == _fontList.end())
        throw AllegroException("Font not initialized", "AllegroText");
    al_draw_text(_fontList[pairCreate], color, x, y, ALLEGRO_ALIGN_LEFT, text.c_str());
}

void AllegroText::destroyAllFont()
{
    for (auto it : _fontList)
        al_destroy_font(it.second);
    _fontList.clear();
}

AllegroText::~AllegroText()
{
}
}