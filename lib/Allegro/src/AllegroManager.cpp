/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** AllegroManager
*/

#include "AllegroManager.hpp"

namespace AllegroManager {
AllegroManager::AllegroManager() : _isWindowOpen(false), _window(NULL)
{
}

void AllegroManager::initAllegro() const
{
    if (al_install_system(ALLEGRO_VERSION_INT, NULL) == false)
        throw AllegroException("Can't initialize Allegro", "AllegroManager");
}

void AllegroManager::display() const
{
    al_flip_display();
}

void AllegroManager::createWindow(const int width, const int height)
{
    _window = al_create_display(width, height);
    _isWindowOpen = true;
    if (_window == NULL) {
        _isWindowOpen = false;
        throw AllegroException("Error during window's creation", "AllegroManager");
    }
}

void AllegroManager::clearWindow(int r, int g, int b)
{
    if (r < 0 || r > 255)
        throw AllegroException("r color need to be between 0 and 255");
    if (g < 0 || g > 255)
        throw AllegroException("r color need to be between 0 and 255");
    if (b < 0 || b > 255)
        throw AllegroException("r color need to be between 0 and 255");
    al_clear_to_color(al_map_rgb(r, g, b));
}

void AllegroManager::destroyWindow()
{
    al_destroy_display(_window);
}

bool AllegroManager::isWindowOpen() const
{
    return _isWindowOpen;
}

ALLEGRO_DISPLAY *AllegroManager::getWindow()
{
    return (_window);
}

AllegroManager::~AllegroManager()
{
}
}