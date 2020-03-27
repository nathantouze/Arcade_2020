/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Centi
*/

#ifndef CENTI_HPP_
#define CENTI_HPP_

#include "Entity.hpp"
#include "MushroomManager.hpp"
#include <vector>

enum Direction {
    LEFT,
    RIGHT
};

class Centi {
    public:
        Centi(int length);
        Centi(std::vector<Entity *> bodyEntities, Direction direction);
        bool isCenti(int posX, int posY) const;
        void oneCycleLoop(const MushroomManager &mushroomManager, ScoreManager &scoreManager);
        std::vector<Entity *> &getCenti();
        Direction getDirection(void);
        std::vector<Entity *> getEntities();
        ~Centi();

    protected:
    private:
        void moveCenti(int posX, int posY, ScoreManager &scoreManager);
        std::vector<Entity *> _bodyEntities;
        Direction _direction;
};

#endif /* !CENTI_HPP_ */
