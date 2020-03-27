/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ILibGame
*/

#ifndef ILIBGAME_HPP_
#define ILIBGAME_HPP_

#include "Event.hpp"
#include "Entity.hpp"
#include <vector>

class ILibGame {
    public:
    virtual ~ILibGame() = default;
    virtual const std::vector<Entity *> &getEntities() = 0;
    virtual void receiveEvent(Event event) = 0;
    virtual void oneCycleLoop() = 0;
    virtual void initGame(const std::string &username) = 0;
    virtual void closeGame() = 0;
};

#endif /* !ILIBGAME_HPP_ */
