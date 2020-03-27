/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Mushroom
*/

#include "Mushroom.hpp"

//gerer les bons typeentity
Mushroom::Mushroom(int posX, int posY) : Entity(MUSHROOM_1, posX, posY), _lives(5)
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
        setType(MUSHROOM_1);
    if (_lives == 3 || _lives == 2)
        setType(MUSHROOM_2);
    if (_lives == 1)
        setType(MUSHROOM_3);
}