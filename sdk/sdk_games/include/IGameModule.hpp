/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019_bootstrap
** File description:
** IDisplayModule
*/

#ifndef IGAMEMODULE_HPP_
#define IGAMEMODULE_HPP_

#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include "KeyBind.hpp"
#include "Entity.hpp"

class IGameModule {
    public:
        virtual ~IGameModule() = default;
        virtual void receiveEvent(KeyBind key) = 0;
        virtual const std::vector<IEntity *> &getEntities() = 0;
        virtual bool oneCycleLoop() = 0;
        virtual int getScore() const = 0;
        virtual void initGame() = 0;
        virtual void closeGame() = 0;
};
#endif /* !IGAMEMODULE_HPP_ */