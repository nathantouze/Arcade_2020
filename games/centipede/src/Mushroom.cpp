/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mushroom
*/

#include "Mushroom.hpp"

Mushroom::Mushroom(int posX, int posY) : Entity(TypeEntity::WALL_2, posX, posY), _lives(5)
{
}

Mushroom::~Mushroom()
{
}

int Mushroom::getLives() const
{
    return _lives;
}

void Mushroom::setLives(int lives)
{
    _lives = lives;

    if (_lives == 5 || _lives == 4)
        setType(WALL_2);
    if (_lives == 3 || _lives == 2)
        setType(WALL_3);
    if (_lives == 1)
        setType(WALL_4);
}