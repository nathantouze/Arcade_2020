/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** MushroomManager
*/

#include "MushroomManager.hpp"
#include <time.h>

MushroomManager::MushroomManager()
{
}

MushroomManager::~MushroomManager()
{
}

void MushroomManager::initRandomMushrooms()
{
    srand(time(NULL));
    int nbMushrooms = rand() % 20 + 30;

    for (int i = 0; i < nbMushrooms; i++) {
        int x = rand()%28 + 1;
        int y = rand()%24 + 1;
        if (isMushroom(x, y) == false)
            _mushrooms.push_back(new Mushroom(x, y));
    }
}

void MushroomManager::resetActualMushrooms(ScoreManager &scoreManager)
{
    for (auto it : _mushrooms)
        if (it->getLives() != 5) {
            it->setLives(5);
            scoreManager.resetMushroom();
        }
}

bool MushroomManager::isMushroom(int posX, int posY) const
{
    for (auto it : _mushrooms)
        if (it->getPosX() == posX && it->getPosY() == posY)
            return (true);
    return (false);
}

void MushroomManager::hitMushroom(int posX, int posY, ScoreManager &scoreManager)
{
    int numero = 0;

    for (auto it : _mushrooms) {
        if (it->getPosX() == posX && it->getPosY() == posY) {
            it->setLives(it->getLives() - 1);
            if (it->getLives() == 0) {
                _mushrooms.erase(_mushrooms.begin() + numero);
                scoreManager.breakMushroom();
            }
        }
        numero++;
    }
}

void MushroomManager::addMushroom(int posX, int posY)
{
    _mushrooms.push_back(new Mushroom(posX, posY));
}

void MushroomManager::deleteAllMushroom()
{
    _mushrooms.clear();
}

std::vector<Entity *> MushroomManager::getMushroomsAsEntities() const
{
    std::vector<Entity *> entities;

    for (auto it : _mushrooms)
        entities.push_back((Entity *)(it));
    return entities;
}