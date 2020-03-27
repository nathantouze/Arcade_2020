/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ShootManager
*/

#include "ShootManager.hpp"

ShootManager::ShootManager() : Entity(SHOOT, 0, 0), _active(false)
{
}

ShootManager::~ShootManager()
{
}

bool ShootManager::isActiveShoot() const
{
    return _active;
}

void ShootManager::initShoot(int x, int y)
{
    setPosX(x);
    setPosY(y);
    _active = true;
}

void ShootManager::oneCycleLoop(MushroomManager &mushroomManager, ScoreManager &scoreManager, InsectsManager &insectsManager)
{
    int nextPosY = getPosY() - 1;

    if (_active == false)
        return;
    if (mushroomManager.isMushroom(getPosX(), nextPosY) == true) {
        mushroomManager.hitMushroom(getPosX(), nextPosY, scoreManager);
        _active = false;
        return;
    }
    if (insectsManager.isCenti(getPosX(), nextPosY) == true) {
        insectsManager.hitCenti(getPosX(), nextPosY, scoreManager);
        mushroomManager.addMushroom(getPosX(), nextPosY);
        _active = false;
        return;
    }
    if (nextPosY <= 0) {
        _active = false;
        return;
    }
    setPosY(nextPosY);
}

Entity *ShootManager::getEntity() const
{
    return (Entity *)(this);
}