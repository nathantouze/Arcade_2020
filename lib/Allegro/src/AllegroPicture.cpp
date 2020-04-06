/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroPicture
*/

#include "AllegroPicture.hpp"

namespace AllegroManager {
AllegroPicture::AllegroPicture()
{
    if (!al_init_image_addon())
        throw AllegroException("Error during init of image_addon", "AllegroPicture");
}

void AllegroPicture::loadPicture(const std::string &path)
{
    if (_bitmapList.find(path) != _bitmapList.end())
        return;
    _bitmapList[path] = al_load_bitmap(path.c_str());
    if (_bitmapList[path] == NULL)
        throw AllegroException("Error during load image " + path, "AllegroPicture");
}

void AllegroPicture::displayPicture(const std::string &path, int x, int y)
{
    if (_bitmapList.find(path) == _bitmapList.end())
        throw AllegroException("Error during image display of " + path, "AllegroPicture");
    al_draw_bitmap(_bitmapList[path], x, y, 0);
}

AllegroPicture::~AllegroPicture()
{
}
}