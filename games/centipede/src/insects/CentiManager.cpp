/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** CentiManager
*/

#include "insects/CentiManager.hpp"
#include <time.h>

CentiManager::CentiManager()
{
}

void CentiManager::releaseNewCenti()
{
    srand(time(NULL));
    int length = rand() % 10 + 10;

    _centiList.push_back(new Centi(length));
}

void CentiManager::destroyAllCenti()
{
    _centiList.clear();
}

bool CentiManager::isCentiOnMap() const
{
    if (_centiList.size() == 0)
        return (false);
    return (true);
}

bool CentiManager::isCenti(int posX, int posY) const
{
    for (auto it : _centiList)
        if (it->isCenti(posX, posY) == true)
            return (true);
    return (false);
}

void CentiManager::eraseEmptyCenti()
{
    int numero = 0;
    bool changed = true;
    while (changed == true) {
        changed = false;
        for (auto it : _centiList) {
            if (it->getCenti().size() <= 0) {
                _centiList.erase(_centiList.begin() + numero);
                numero = 0;
                changed = true;
                break;
            }
            numero++;
        }
    }
}

void CentiManager::oneCycleLoop(MushroomManager &mushroomManager, ScoreManager &scoreManager)
{
    eraseEmptyCenti();
    for (auto it : _centiList)
        it->oneCycleLoop(mushroomManager, scoreManager);
}

void CentiManager::hitCenti(int posX, int posY, ScoreManager &scoreManager)
{
    Direction direction;
    std::vector<Entity *> centi;
    int i = 0;
    int numero = 0;
    int posOfHit = 0;

    eraseEmptyCenti();
    for (auto it : _centiList) {
        if (it->isCenti(posX, posY) == true) {
            direction = it->getDirection();
            centi = it->getCenti();
            _centiList.erase(_centiList.begin() + numero);
            scoreManager.breakCentipede();
            i = 0;
            for (auto it : centi) {
                if (it->getPosX() == posX && it->getPosY() == posY)
                    posOfHit = i;
                i++;
            }
            if (posOfHit == 0) {
                std::vector<Entity *> part(centi.begin() + 1, centi.end());
                _centiList.push_back(new Centi(part, direction));
            } else if (posOfHit == (int)(centi.size()) - 1) {
                std::vector<Entity *> part(centi.begin(), centi.begin() + centi.size() - 1);
                _centiList.push_back(new Centi(part, direction));
            } else {
                std::vector<Entity *> part(centi.begin(), centi.begin() + posOfHit);
                std::vector<Entity *> part2(centi.begin() + posOfHit + 1, centi.end());
                _centiList.push_back(new Centi(part, direction));
                _centiList.push_back(new Centi(part2, direction));
            }
            return;
        }
        numero++;
    }
}

std::vector<Entity *> CentiManager::getEntities() const
{
    std::vector<Entity *> entities;

    for (auto it : _centiList)
        for (auto itr : it->getEntities())
            entities.push_back(itr);
    return (entities);
}

CentiManager::~CentiManager()
{
}
