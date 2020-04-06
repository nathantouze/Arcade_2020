/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Gnome
*/

#include "Gnome.hpp"

Gnome::Gnome() : Entity(TypeEntity::PLAYER_1, 15, 31)
{
}

Gnome::~Gnome()
{
}

void Gnome::initGnome()
{
    _isAlive = true;
    setPosX(15);
    setPosY(31);
}

void Gnome::moveUp(const MushroomManager &mushroomManager)
{
    int actualPosY = getPosY();

    if (actualPosY <= 25)
        setPosY(25);
    else if (mushroomManager.isMushroom(getPosX(), actualPosY - 1) == false)
        setPosY(actualPosY - 1);
}

void Gnome::moveDown(const MushroomManager &mushroomManager)
{
    int actualPosY = getPosY();

    if (actualPosY >= 31)
        setPosY(31);
    else if (mushroomManager.isMushroom(getPosX(), actualPosY + 1) == false)
        setPosY(actualPosY + 1);
}

void Gnome::moveLeft(const MushroomManager &mushroomManager)
{
    int actualPosX = getPosX();

    if (actualPosX <= 0)
        setPosX(0);
    else if (mushroomManager.isMushroom(actualPosX - 1, getPosY()) == false)
        setPosX(actualPosX - 1);
}

void Gnome::moveRight(const MushroomManager &mushroomManager)
{
    int actualPosX = getPosX();

    if (actualPosX >= 30)
        setPosX(30);
    else if (mushroomManager.isMushroom(actualPosX + 1, getPosY()) == false)
        setPosX(actualPosX + 1);
}

bool Gnome::isAlive() const
{
    return _isAlive;
}

void Gnome::setIsAlive(bool isAlive)
{
    _isAlive = isAlive;
}

Entity *Gnome::getEntity()
{
    return (Entity *)(this);
}