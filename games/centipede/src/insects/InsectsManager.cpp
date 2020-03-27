/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** InsectsManager
*/

#include "insects/InsectsManager.hpp"

InsectsManager::InsectsManager()
{
    _centiKill = 0;
    _centiManager.releaseNewCenti();
}

void InsectsManager::destroyAllInsects()
{
    _centiManager.destroyAllCenti();
}

void InsectsManager::setCentiKill(int centiKill)
{
    _centiKill = centiKill;
}

void InsectsManager::oneCycleLoop(MushroomManager &mushroomManager, ScoreManager &scoreManager)
{
    if (_centiManager.isCentiOnMap() == false) {
        if (_centiKill == 0)
            _centiManager.releaseNewCenti();
        else {
            _centiKill++;
            _centiManager.releaseNewCenti();
        }
    }
    _centiManager.oneCycleLoop(mushroomManager, scoreManager);
}

int InsectsManager::getCentiKill() const
{
    return _centiKill;
}

bool InsectsManager::isCenti(int posX, int posY) const
{
    return _centiManager.isCenti(posX, posY);
}

void InsectsManager::hitCenti(int posX, int posY, ScoreManager &scoreManager)
{
    _centiManager.hitCenti(posX, posY, scoreManager);
}

std::vector<Entity *> InsectsManager::getEntities() const
{
    std::vector<Entity *> entities;

    for (auto it : _centiManager.getEntities())
        entities.push_back(it);
    return (entities);
}

InsectsManager::~InsectsManager()
{
}
