/*
** EPITECH PROJECT, 2023
** OOP_arcade_2019
** File description:
** Created by ntouze,
*/
#ifndef OOP_ARCADE_2019_ILIBIO_HPP
#define OOP_ARCADE_2019_ILIBIO_HPP

#include "Event.hpp"
#include "IEntity.hpp"
#include "MenuInfo.hpp"
#include <string>
#include <vector>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class ILibIO {
    public:
    virtual void initWindow() = 0;
    virtual void display() const = 0;
    virtual void drawEntity(const IEntity &entity) = 0;
    virtual void displayMenu(const MenuInfo &menu) = 0;
    virtual bool isOpen() const = 0;
    virtual Event eventListener() const = 0;
    virtual void clearWindow() = 0;
    virtual void destroyWindow() = 0;
    virtual ~ILibIO() = default;
};

#endif //OOP_ARCADE_2019_ILIBIO_HPP
