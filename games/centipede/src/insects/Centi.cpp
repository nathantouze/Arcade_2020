/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centi
*/

#include "insects/Centi.hpp"

Centi::Centi(int length)
{
    for (int i = 0; i < length; i++)
        _bodyEntities.push_back(new Entity(BONUS, 15, -i));
    _direction = RIGHT;
}

Centi::Centi(std::vector<Entity *> bodyEntities, Direction direction)
{
    _bodyEntities = bodyEntities;
    _direction = direction;
}

bool Centi::isCenti(int posX, int posY) const
{
    for (auto it : _bodyEntities)
        if (it->getPosX() == posX && it->getPosY() == posY)
            return (true);
    return (false);
}

void Centi::moveCenti(int posX, int posY, ScoreManager &scoreManager)
{
    _bodyEntities.pop_back();
    if (_bodyEntities.size() == 0) {
        scoreManager.centiOnBot();
        return;
    }
    if (posY > 31) {
        if (_direction == RIGHT)
            _direction = LEFT;
        else
            _direction = RIGHT;
        _bodyEntities.erase(_bodyEntities.begin());
        scoreManager.centiOnBot();
    } else 
        _bodyEntities.insert(_bodyEntities.begin(), new Entity(BONUS, posX, posY));
}

void Centi::oneCycleLoop(const MushroomManager &mushroomManager, ScoreManager &scoreManager)
{
    int nextPosX = _bodyEntities[0]->getPosX();
    int nextPosY = _bodyEntities[0]->getPosY();

    if (_direction == RIGHT)
        nextPosX += 1;
    if (_direction == LEFT)
        nextPosX -= 1;
    if (nextPosX < 0) {
        _direction = RIGHT;
        moveCenti(0, nextPosY + 1, scoreManager);
        return;
    }
    if (nextPosX > 30) {
        _direction = LEFT;
        moveCenti(30, nextPosY + 1, scoreManager);
        return;
    }
    if (mushroomManager.isMushroom(nextPosX, nextPosY) == true) {
        if (_direction == RIGHT)
            _direction = LEFT;
        else
            _direction = RIGHT;
        moveCenti(_bodyEntities[0]->getPosX(), nextPosY + 1, scoreManager);
        return;
    }
    moveCenti(nextPosX, nextPosY, scoreManager);
}

std::vector<Entity *> &Centi::getCenti()
{
    return _bodyEntities;
}

Direction Centi::getDirection()
{
    return _direction;    
}

std::vector<Entity *> Centi::getEntities()
{
    std::vector<Entity *> entities;

    for (auto it : _bodyEntities) {
        if (it->getPosY() >= 0)
            entities.push_back(it);
    }
    return (entities);
}

Centi::~Centi()
{
}
