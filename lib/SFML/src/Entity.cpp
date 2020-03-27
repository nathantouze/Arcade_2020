/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by jserenne,
*/

#include "Entity.hpp"

Entity::Entity(TypeEntity type, int x, int y) :
    _type(type), _x(x), _y(y)
{}

Entity::~Entity() = default;

TypeEntity Entity::getType() const
{
    return _type;
}

void Entity::setType(TypeEntity type)
{
    _type = type;
}

int Entity::getPosX() const
{
    return _x;
}

void Entity::setPosX(int x)
{
    _x = x;
}

int Entity::getPosY() const
{
    return _y;
}

void Entity::setPosY(int y)
{
    _y = y;
}

void Entity::updatePos(int x, int y)
{
    _x = x;
    _y = y;
}